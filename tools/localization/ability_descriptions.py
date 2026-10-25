#!/usr/bin/env python3
"""Build source-reviewed ability descriptions, capped to the existing 144px line."""
import json
import re
import subprocess

import catalog
import reference_names

# Corrections found by comparing every English/reference description. In
# particular, STENCH's old overworld wording must not replace its flinch effect.
OVERRIDES = {
    'STENCH': 'あいてをひるませることがある',
    'STURDY': 'いちげきひっさつがきかない',
    'SNOW_CLOAK': 'あられやゆきでかいひりつアップ',
    'ICE_BODY': 'あられやゆきでHPかいふく',
    'SLUSH_RUSH': 'あられやゆきですばやさアップ',
    'SKILL_LINK': 'れんぞくわざが5かいあたる',
    'HEAVY_METAL': 'たいじゅうが2ばいになる',
    'LIGHT_METAL': 'たいじゅうがはんぶんになる',
    'MULTISCALE': 'HPまんたんでダメージはんげん',
    'SHADOW_SHIELD': 'HPまんたんでダメージはんげん',
    'WATER_BUBBLE': 'ほのおややけどからみをまもる',
    'BERSERK': 'ピンチでとくこうがあがる',
    'FLUFFY': 'せっしょくにつよくほのおによわい',
    'GULP_MISSILE': 'うみのえものをひだんじにはく',
    'PUNK_ROCK': 'おとわざにつよくいりょくもアップ',
    'ICE_FACE': 'あられやゆきでみがわりさいせい',
    'POWER_SPOT': 'みかたのわざがつよくなる',
    'PERISH_BODY': 'ふれると3ターンごおたがいひんし',
    'UNSEEN_FIST': 'せっしょくわざがまもりをむしする',
    'PIERCING_DRILL': 'せっしょくわざがまもりをむしする',
    'AS_ONE_ICE_RIDER': 'きんちょうかんとしろのいななき',
    'AS_ONE_SHADOW_RIDER': 'きんちょうかんとくろのいななき',
    'MINDS_EYE': 'するどいめときもったま',
    'TERA_SHIFT': 'とうじょうじにテラスタルする',
    'BEAST_BOOST': 'たおすとさいこうののうりょくアップ',
    'PROTOSYNTHESIS': 'はれでさいこうののうりょくアップ',
    'QUARK_DRIVE': 'エレキばでさいだいのうりょくUP',
}


def main():
    root = catalog.ROOT
    name = 'src/data/abilities.h'
    old = subprocess.check_output(['git', 'show', '23be896714:'+name], cwd=root, text=True)
    ref = (root.parent/'reference-jp'/name).read_text()
    source = reference_names.fields(old, ('description',))
    target = reference_names.fields(ref, ('description',))
    rows = json.loads((root/'localization/catalog.json').read_text())
    by_pos = {(r['file'], r['start']): r for r in rows}
    charmap = set(re.findall(r"^'(.)'\s*=", (root/'charmap.txt').read_text(), re.M))
    batch = []
    for key, entries in source.items():
        if len(target.get(key, [])) != len(entries):
            raise ValueError('variant mismatch: '+str(key))
        for variant, (entry, candidate) in enumerate(zip(entries, target[key])):
            row = by_pos[(name, entry['start'])]
            symbol = key[0].removeprefix('ABILITY_')
            text = OVERRIDES.get(symbol, re.sub(r'\{(?:JPN|ENG)\}', '', candidate['source']))
            if len(text) > 18:
                text = text.replace(' ', '')
            if len(text) > 18:
                raise ValueError('144px line exceeded: '+symbol+': '+text)
            translation = '{JPN}'+text+'{ENG}'
            catalog.validate({**row, 'translation': translation}, charmap)
            batch.append(dict(id=row['id'], translation=translation,
                target=key[0]+'.description['+str(variant)+']',
                provenance=dict(method='English/reference pair reviewed; bounded ability description',
                    reference_commit=reference_names.REFERENCE_COMMIT,
                    corrected_from_english=symbol in OVERRIDES, max_glyphs=18)))
    (root/'localization/batches/ability-descriptions-01.json').write_text(json.dumps(batch, ensure_ascii=False, indent=2)+'\n')
    print(json.dumps(dict(proposed=len(batch), overrides=len(OVERRIDES))))


if __name__ == '__main__':
    main()

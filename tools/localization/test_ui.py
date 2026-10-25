import copy
import json
import re
import unittest

import catalog
import reference_names
import ui_common
import update_catalog
import test_update_catalog


class UiTextTests(unittest.TestCase):
    def test_color_prefix_survives_selection_highlighter(self):
        result = ui_common.scoped('{COLOR GREEN}{SHADOW LIGHT_GREEN}あり')
        self.assertTrue(result.startswith('{COLOR GREEN}{SHADOW LIGHT_GREEN}{JPN}'))

    def test_variable_language_restored_before_japanese_suffix(self):
        result = ui_common.scoped('{STR_VAR_1}をもたせる')
        self.assertIn('{ENG}{STR_VAR_1}{JPN}を', result)

    def test_reset_precedes_script_terminator(self):
        result = ui_common.scoped('おわり$')
        self.assertTrue(result.endswith('{ENG}$'))

    def test_choices_fit_copy_buffers(self):
        rows = json.loads((catalog.ROOT/'localization/catalog.json').read_text())
        cmap = set(re.findall(r"^'(.)'\s*=", (catalog.ROOT/'charmap.txt').read_text(), re.M))
        for row in rows:
            capacity = {'src/option_menu.c': 32, 'src/wot_randomizer_menu.c': 24}.get(row['file'])
            if capacity and row['status'] == 'translated' and row['source'].startswith('{COLOR GREEN}{SHADOW LIGHT_GREEN}'):
                text = row['translation'].removeprefix('{COLOR GREEN}{SHADOW LIGHT_GREEN}')
                self.assertLessEqual(6 + reference_names.encoded_length(text, cmap) + 1, capacity, row['id'])


class CodeOffsetTests(unittest.TestCase):
    setUp = test_update_catalog.UpdateTests.setUp
    tearDown = test_update_catalog.UpdateTests.tearDown

    def test_code_insertion_keeps_original_ids_and_offsets(self):
        rows = copy.deepcopy(self.rows)
        # A non-text source insertion is tracked separately from translation deltas.
        self.file.write_text(self.file.read_text().replace('; _', '; /*ui*/ _'))
        rows[1]['code_offset'] = 7
        updated, output = update_catalog.plan(rows, [dict(id='b', translation='{JPN}い')], {'あ','い'})
        self.assertIn('/*ui*/ _("{JPN}い")', output[self.file])
        self.assertEqual(updated[1]['start'], self.rows[1]['start'])
        with self.assertRaisesRegex(ValueError, 'immutable'):
            update_catalog.plan(rows, [dict(id='b', translation='い', code_offset=0)], {'い'})

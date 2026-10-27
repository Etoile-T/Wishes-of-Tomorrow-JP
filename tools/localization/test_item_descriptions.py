import unittest
import item_descriptions as d
import catalog

class ItemDescriptionTests(unittest.TestCase):
    def test_item_macros_and_size_limit_extracted(self):
        text = 'ITEM_NAME("Potion") ITEM_PLURAL_NAME("Potions") COMPOUND_STRING_SIZE_LIMIT("Text", 20)'
        self.assertEqual([m[1] for m in catalog.MACRO.finditer(text)], ['"Potion"', '"Potions"', '"Text"'])

    def test_logo_and_language_tokens_remain_whole(self):
        result = d.wrap('あ' * 12 + '{ENG}{POKEBLOCK}{JPN}ケース')
        self.assertIn('{ENG}', result)
        self.assertIn('{POKEBLOCK}', result)
        self.assertEqual(result.replace(r'\n', ''), 'あ' * 12 + '{ENG}{POKEBLOCK}{JPN}ケース')

    def test_oversized_description_refused(self):
        with self.assertRaises(ValueError):
            d.wrap('あ' * 40)

    def test_unknown_variable_width_refused(self):
        with self.assertRaises(ValueError):
            d.wrap('{PLAYER}')

    def test_current_type_strings_fit_rom_fields(self):
        import json, re
        import reference_names
        rows = json.loads((catalog.ROOT / 'localization/catalog.json').read_text())
        cmap = set(re.findall(r"^'(.)'\s*=", (catalog.ROOT / 'charmap.txt').read_text(), re.M))
        count = 0
        for row in rows:
            if row['file'] == 'src/data/types_info.h' and row['status'] == 'translated':
                budget = 12 if 'move' not in row['source'] else 16
                self.assertLessEqual(reference_names.encoded_length(row['translation'], cmap), budget)
                count += 1
        self.assertEqual(count, 42)

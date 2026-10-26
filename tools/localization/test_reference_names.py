import unittest

import reference_names as r


class ReferenceNameTests(unittest.TestCase):
    def test_balanced_entries_ignore_shared_macros_comments_and_other_fields(self):
        text = '''#define SHARED .speciesName = _("Shared")
// [SPECIES_FAKE] = { .speciesName = _("Fake") },
[SPECIES_TEST] = {
 .types = {TYPE_FIRE, TYPE_NONE},
 .speciesName = _("Test"),
 .description = COMPOUND_STRING("{PLAYER} text"),
},
'''
        fields = r.fields(text)
        self.assertEqual(list(fields), [('SPECIES_TEST', 'speciesName')])
        self.assertEqual(fields[('SPECIES_TEST', 'speciesName')][0]['source'], 'Test')

    def test_variant_order_retained(self):
        fields = r.fields('[MOVE_TEST] = {\n#if A\n.name = COMPOUND_STRING("One"),\n#else\n.name = COMPOUND_STRING("Two"),\n#endif\n},')
        self.assertEqual([x['source'] for x in fields[('MOVE_TEST', 'name')]], ['One', 'Two'])

    def test_encoded_budget_counts_controls(self):
        name = r.scoped_name('ピカチュウ')
        self.assertEqual(name, '{JPN}ピカチュウ{ENG}')
        self.assertEqual(r.encoded_length(name, set('ピカチュウ')), 9)
        self.assertEqual(r.scoped_name(name), name)

    def test_long_bounded_species_name_budget(self):
        name = '{JPN_NAME_10}アーマードミュウツー'
        self.assertEqual(r.encoded_length(name, set('アーマードミュウツー')), 12)

    def test_unknown_control_and_glyph_refused(self):
        for text in ('{JPN}漢字{ENG}', '{PLAYER}'):
            with self.assertRaises(ValueError):
                r.encoded_length(text, set('あいうえお'))


if __name__ == '__main__':
    unittest.main()

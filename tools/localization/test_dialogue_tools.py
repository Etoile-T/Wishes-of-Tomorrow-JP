import importlib.util
import pathlib
import sys
import unittest
sys.path.insert(0, str(pathlib.Path(__file__).parent))
spec = importlib.util.spec_from_file_location('dialogue_tools', pathlib.Path(__file__).with_name('dialogue_tools.py'))
d = importlib.util.module_from_spec(spec)
spec.loader.exec_module(d)

class DialogueToolsTests(unittest.TestCase):
    def test_cells_count_glyphs_and_placeholders(self):
        self.assertEqual(d.cells('{JPN}あいう{ENG}'), 3)
        self.assertEqual(d.cells('{ENG}{PLAYER}{JPN}は'), 8)
        self.assertEqual(d.cells('{STR_VAR_1}を'), 11)

if __name__ == '__main__':
    unittest.main()

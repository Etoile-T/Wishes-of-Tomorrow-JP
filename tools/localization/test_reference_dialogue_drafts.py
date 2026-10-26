import unittest
from reference_dialogue_drafts import align


class ReferenceDialogueTest(unittest.TestCase):
    def test_same_shape_splits_at_original_rows(self):
        rows=[dict(id='a',source='Hello.\\n'),dict(id='b',source='Bye, {PLAYER}.$')]
        result=align(rows,'こんにちは。\\nまたね {PLAYER}。$')
        self.assertEqual([x['id'] for x in result],['a','b'])
        self.assertEqual(''.join(x['draft'] for x in result),'こんにちは。\\nまたね {PLAYER}。$')

    def test_different_page_shape_is_rejected(self):
        self.assertIsNone(align([dict(id='a',source='Hello.\\pBye.$')],'こんにちは。\\nまたね。$'))

    def test_variable_cannot_move_to_different_row(self):
        rows=[dict(id='a',source='{PLAYER}\\n'),dict(id='b',source='Bye.$')]
        self.assertIsNone(align(rows,'こんにちは。\\n{PLAYER} またね。$'))


if __name__=='__main__':unittest.main()

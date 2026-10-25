import hashlib
import unittest

import bps
from apply_verified_patch import checked_apply


class VerifiedPatchTests(unittest.TestCase):
    def setUp(self):
        self.source = b'correct English build'
        self.target = b'Japanese build'
        self.patch = bps.create(self.source, self.target)
        self.manifest = {key + '_sha256': hashlib.sha256(data).hexdigest()
                         for key, data in [('source', self.source), ('target', self.target), ('patch', self.patch)]}

    def test_correct_pair(self):
        self.assertEqual(checked_apply(self.source, self.patch, self.manifest), self.target)

    def test_wrong_base_and_double_patching_rejected(self):
        for source in (b'clean Emerald instead of Wishes', self.target):
            with self.assertRaisesRegex(ValueError, 'source SHA256 mismatch'):
                checked_apply(source, self.patch, self.manifest)

    def test_wrong_patch_and_wrong_target_manifest_rejected(self):
        with self.assertRaisesRegex(ValueError, 'patch SHA256 mismatch'):
            checked_apply(self.source, self.patch + b'x', self.manifest)
        with self.assertRaisesRegex(ValueError, 'target SHA256 mismatch'):
            checked_apply(self.source, self.patch, {**self.manifest, 'target_sha256': '0'*64})

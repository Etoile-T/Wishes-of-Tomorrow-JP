import importlib.util,pathlib,unittest
spec=importlib.util.spec_from_file_location('bps',pathlib.Path(__file__).with_name('bps.py'))
b=importlib.util.module_from_spec(spec); spec.loader.exec_module(b)
class BpsTests(unittest.TestCase):
    def test_number_vectors(self):
        self.assertEqual(b.number(0), b'\x80')
        self.assertEqual(b.number(127), b'\xff')
        self.assertEqual(b.number(128), b'\x00\x80')
    def test_delta_roundtrip_with_relocated_blocks(self):
        source=bytes(range(256))*100
        target=source[2048:]+b'new translation'+source[:2048]
        patch=b.create(source,target)
        self.assertEqual(b.apply(source,patch),target)
        self.assertLess(len(patch),len(target))
    def test_reject_wrong_source_and_corruption(self):
        patch=b.create(b'English source',b'Japanese target')
        with self.assertRaises(ValueError): b.apply(b'wrong source',patch)
        corrupt=bytearray(patch); corrupt[5]^=1
        with self.assertRaises(ValueError): b.apply(b'English source',corrupt)
    def test_empty_and_unequal_sizes(self):
        for source,target in [(b'',b''),(b'',b'a'),(b'abc',b''),(b'abc',b'abcd')]:
            self.assertEqual(b.apply(source,b.create(source,target)),target)
if __name__=='__main__': unittest.main()

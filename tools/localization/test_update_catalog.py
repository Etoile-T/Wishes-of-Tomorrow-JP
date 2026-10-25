import pathlib,tempfile,unittest
import catalog,update_catalog
class UpdateTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory(); self.original=catalog.ROOT
        catalog.ROOT=pathlib.Path(self.temp.name)
        self.file=(catalog.ROOT/'a.c').resolve(); self.file.write_text('_("{JPN}あ"); _("two");')
        self.rows=[dict(id='a',file='a.c',line=1,start=2,end=7,raw='"one"',source='one',translation='{JPN}あ',status='translated',kind='encoded_c'),dict(id='b',file='a.c',line=1,start=12,end=17,raw='"two"',source='two',translation='',status='pending',kind='encoded_c')]
    def tearDown(self): catalog.ROOT=self.original; self.temp.cleanup()
    def test_incremental_apply_and_repeat(self):
        rows,out=update_catalog.plan(self.rows,[dict(id='b',translation='{JPN}い')],{'あ','い'})
        self.assertEqual(out[self.file],'_("{JPN}あ"); _("{JPN}い");')
        self.file.write_text(out[self.file])
        _,again=update_catalog.plan(rows,[dict(id='b',translation='{JPN}い')],{'あ','い'})
        self.assertEqual(out,again)
    def test_stale_refused_without_writes(self):
        self.file.write_text('edited')
        with self.assertRaises(ValueError): update_catalog.plan(self.rows,[dict(id='b',translation='い')],{'い'})
        self.assertEqual(self.file.read_text(),'edited')
    def test_duplicate_and_metadata_changes_refused(self):
        for updates in [[dict(id='b',translation='い')]*2,[dict(id='b',translation='い',file='elsewhere')]]:
            with self.assertRaises(ValueError): update_catalog.plan(self.rows,updates,{'い'})
    def test_placeholder_loss_refused(self):
        with self.assertRaises(ValueError): update_catalog.plan(self.rows,[dict(id='b',translation='{PLAYER}')],set())

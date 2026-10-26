#!/bin/zsh
cd -- "$(dirname -- "$0")/../.." || exit 1
print '翻訳管理画面: http://127.0.0.1:8766'
print '終了するには、このウィンドウで Control+C を押してください。'
python3 tools/localization/admin.py "$@"

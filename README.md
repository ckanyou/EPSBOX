Windows11での動作の確認をしています。MacやLinuxではうまく動きません。

python3.10.6,Unity2021.3.4f1,Arduino2.2.0を使用しました。

pythonは、C:\の直下にPythonという名前のフォルダを作りeps-envという仮想環境を作ってください。
![スクリーンショット 2023-08-31 154232](https://github.com/ckanyou/EPSBOX/assets/111338670/661335a2-1f6f-4736-bd61-ddd7b44a7eab)

pythonに必要なライブラリ

pytorch,

tramsformers,

fugashi,

ipadic,

SpeechRecognition,

pyaudio

インストール方法

pytorchはご自身の環境に合わせてください。

https://pytorch.org

pip install  transformers fugashi fugashi[unidic-lite] ipadic SpeechRecognition pyaudio

※pytorchを入れないとtransformersが動きません。

※pyaudioを入れないとSpeechRecognitionがうまく動きません。

vrec_frecog.pyは、Pythonフォルダの中に入れておいてください。

Arduinoの配置：

中央ボタン　arduinoの7ピン

左ボタン　arduinoの8ピン

右ボタンをarduinoの12ピン

ホール素子起動確認　arduinoの２ピン

ホール素子データ受け取り　arduinoのA0ピン

サーボモーター　arduinoの8ピン

Arduinoにepsbix_02をいれればセットアップは完了です。

あとは、EPSBOXMainにあるEPSBOX.exeを実行するだけです。

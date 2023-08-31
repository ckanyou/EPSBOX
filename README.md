Windows11での動作の確認をしています。MacやLinuxではうまく動きません。
python3.10.6,Unity2021.3.4f1,Arduino2.2.0を使用しました。

Setup

pythonは、C:\の直下にPythonという名前のフォルダを作りeps-envという仮想環境を作ってください。
pythonに必要なライブラリをインストール。
pytorchはご自身の環境に合わせてください。
https://pytorch.org

pip install  transformers fugashi fugashi[unidic-lite] ipadic SpeechRecognition pyaudio

※pytorchを入れないとtransformersが動きません。
※pyaudioを入れないとSpeechRecognitionがうまく動きません。

vrec_frecog.pyは、Pythonフォルダの中に入れておいてください。
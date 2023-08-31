import speech_recognition as sr
from transformers import pipeline 
from transformers import AutoModelForSequenceClassification 
from transformers import BertJapaneseTokenizer 
import os

recognizer = sr.Recognizer()
model = AutoModelForSequenceClassification.from_pretrained('kit-nlp/bert-base-japanese-sentiment-irony') 
tokenizer = BertJapaneseTokenizer.from_pretrained('cl-tohoku/bert-base-japanese-whole-word-masking') 
nlp = pipeline("sentiment-analysis", model=model, tokenizer=tokenizer)

with sr.Microphone() as source:
    audio = recognizer.listen(source)
    text = recognizer.recognize_google(audio, language="ja-JP")
    result = nlp(text)[0]
    label = result['label']
    score = result['score']
    #条件分岐
    if label == "ポジティブ":
        if score >= 0.9:
            result_jp = "最もポジティブです"
        elif score >= 0.8:
            result_jp = "とてもポジティブです"
        elif score >= 0.7:
            result_jp = "ポジティブです"
        elif score >= 0.6:
            result_jp = "まあまあポジティブです"
        else:
            result_jp = "ポジティブと言って差し支えないです"
    elif label == "ネガティブ":
        if score >= 0.9:
            result_jp = "最もネガティブです"
        elif score >= 0.8:
            result_jp = "とてもネガティブです"
        elif score >= 0.7:
            result_jp = "ネガティブです"
        elif score >= 0.6:
            result_jp = "まあまあネガティブです"
        else:
            result_jp = "ネガティブと言って差し支えないです"
    print(result_jp)
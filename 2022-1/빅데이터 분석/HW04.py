from nltk.corpus import stopwords
import nltk
import re

nltk.download('stopwords')
nltk.download('punkt')
nltk.download('wordnet')
stop_words = stopwords.words('english')

def preprocess(text):
    text = text.lower()
    token = nltk.word_tokenize(text)
    token = [nltk.stem.WordNetLemmatizer().lemmatize(t) for t in token]
    name = ["hamlet", "king claudius", "horatio", "laertes", "lucianus", "voltimand", "cornelius",
            "rosencrantz", "guildenstern", "osric", "Gentlemen", "first priest", "marcellus", "lord",
            "bernardo", "francisco", "reynaldo", "first player", "player king", "player queen", "gertrude",
            "first clown", "second clown", "prince fortinbras", "captain", "first ambassador", "ghost",
            "queen gertrude", "ophelia", "first sailor", "messenger", "claudius", "polonius"]
    token = [t for t in token if t not in stop_words + name]
    token = [t for t in token if re.fullmatch('[a-z]+', t)]
    return token

f = open("/content/Hamlet.txt.txt", 'r')
text = f.read()
f.close()

text = preprocess(text)
word = set(text)
counter = dict()
sorted_counter = dict()

for w in word:
    counter[w] = count = text.count(w)

for (key,value) in sorted(counter.items(), key = lambda item: item[1], reverse=True):
    sorted_counter[key] = value

import matplotlib.pyplot as plt

top10 = list(sorted_counter.keys())[:10]
print("Top 10", top10)

plt.bar(top10, list(sorted_counter.values())[:10])
plt.title("Top 10")
plt.show()

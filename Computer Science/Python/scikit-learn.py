import pandas as pd
import random

class Sentiment:
    NEGATIVE = 'NEGATIVE'
    NEUTRAL = 'NEUTRAL'
    POSITIVE = 'POSITIVE'
    sentiments = { 1: NEGATIVE, 2: NEGATIVE, 3: NEUTRAL, 4: POSITIVE, 5: POSITIVE }

class Review:
    def __init__(self, text, score):
        self.text = text
        self.score = score
        self.sentiment = self.get_sentiment()

    def get_sentiment(self):
        return Sentiment.sentiments[self.score]

class ReviewContainer:
    def __init__(self, reviews):
        self.reviews = reviews

    def evenly_distribute(self):
        negative = list(filter(lambda x: x.sentiment == Sentiment.NEGATIVE, self.reviews))
        positive = list(filter(lambda x: x.sentiment == Sentiment.POSITIVE, self.reviews))
        positive_shrunk = positive[:len(negative)]
        self.reviews = negative + positive_shrunk
        random.shuffle(self.reviews)

    def get_texts(self):
        return [x.text for x in self.reviews]

    def get_sentiments(self):
        return [x.sentiment for x in self.reviews]

#df = pd.read_json('/home/kamil/Desktop/books.json', lines=True)
df = pd.read_json('/home/kamil/Desktop/books10000.json', lines=True)
reviews = []

print(list(df.columns))
print()

for index, row in df.iterrows():
    reviews.append(Review(row['reviewText'], row['overall']))

from sklearn.model_selection import train_test_split

# training, test - lists of Review objects
training, test = train_test_split(reviews, test_size=0.33, random_state=42)

training_container = ReviewContainer(training)
training_container.evenly_distribute()
test_container = ReviewContainer(test)
test_container.evenly_distribute()

training_x = training_container.get_texts()
training_y = training_container.get_sentiments()

test_x = test_container.get_texts()
test_y = test_container.get_sentiments()

from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer

vectorizer = TfidfVectorizer()

# training_x_vectors, test_x_vectors - matrices (see: bags of words)
training_x_vectors = vectorizer.fit_transform(training_x)
test_x_vectors = vectorizer.transform(test_x)

from sklearn.naive_bayes import GaussianNB

clf = GaussianNB()
clf.fit(training_x_vectors.toarray(), training_y)

print(clf.score(test_x_vectors.toarray(), test_y))
print()

from sklearn.metrics import f1_score

print(f1_score(test_y, clf.predict(test_x_vectors.toarray()), average=None, labels=[Sentiment.POSITIVE, Sentiment.NEGATIVE]))
print()

test_set = [ 'amazing', 'pathetic', 'waste of time' ]
new_test = vectorizer.transform(test_set)
print(clf.predict(new_test.toarray()))

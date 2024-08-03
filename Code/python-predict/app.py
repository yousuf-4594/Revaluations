import pandas as  pd
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
import os
import sys

path = os.getcwd() + "\\python-predict\\data.csv"
data = pd.read_csv(path)
train = data.drop(['price'], axis=1)
test = data['price']
x_train, x_test, y_train, y_test = train_test_split(train, test, test_size=0.2, random_state=2)
regr = LinearRegression()
regr.fit(x_train.values, y_train)
print(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5], sys.argv[6])
toPredict = np.array(([[int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]), float(sys.argv[4]), int(sys.argv[5]), int(sys.argv[6])]]))

pred = regr.predict(toPredict)

with open(os.getcwd() + "\\python-predict\\price.txt", 'w') as f:
    f.write(str(abs(pred[0])))

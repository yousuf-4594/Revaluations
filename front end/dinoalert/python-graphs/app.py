import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import os

path = os.getcwd() + "\\python-graphs\\"
# print(path)
df = pd.read_csv(path + "data.csv")

# sns.set_palette('husl', 2)
# plt.plot(df['price'])
 
# # Adding Title to the Plot
# plt.title("Scatter Plot")
palette = sns.color_palette("rocket_r")

# Plot the lines on two facets
sns.relplot(data=df, x="area_sqft", y="price")
plt.savefig(path + "plot1.png")


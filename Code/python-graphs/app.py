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


sns.displot(
    data=df,
    x="area_sqft", hue="price_type",
    kind="kde", height=6,
    multiple="fill", clip=(0, None),
    palette="ch:rot=-.25,hue=1,light=.75"
)
plt.xlim(0,10000)

plt.savefig(path + "plot2.png")
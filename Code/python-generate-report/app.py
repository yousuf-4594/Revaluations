import pandas as pd
from pandas_profiling import ProfileReport
import os
import sys
import webbrowser

path = os.getcwd() + "\\data\\"
argument = sys.argv[1]
if len(sys.argv) > 1:
    if argument == "properties":
        fileName = "property.csv"
    elif argument == "sold":
        fileName = "sold.csv"
    elif argument == "users":
        fileName = "users.csv"
    path += fileName
    df = pd.read_csv(path)
# print(df)
profile = ProfileReport(df, title="Pandas Profiling Report", vars={"num": {"low_categorical_threshold": 0}})
profile.to_file(output_file='report.html')
webbrowser.open_new_tab("report.html");
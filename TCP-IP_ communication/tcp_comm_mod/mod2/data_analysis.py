import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from statistics import mean

df = pd.read_csv('time_data.txt',header=None)

my_list = df[0].to_list()

index = [i for i in range(len(my_list))]
print(mean(my_list))
plt.scatter(x = index, y= my_list)
plt.grid()
plt.show()
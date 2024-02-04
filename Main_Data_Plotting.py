# Import necessary libraries
import pandas as pd
import matplotlib.pyplot as plt

data_srings = ['V at L/D Max vs rho', 'others']

# Read the data from the csv file
df = pd.read_csv("CO_AC_Performance_main.csv")

# Separate the columns
# The iloc function is used to select columns by their integer location
# Here, we're selecting the first column (0) and the second column (1)
column1 = df.iloc[:, 0]
column2 = df.iloc[:, 1]

# Plot the data
# The plot function takes two arguments: the x values and the y values
# Here, we're using the data from the first column as the x values and the data from the second column as the y values
plt.plot(column1, column2)

#Plot settings
plt.xlabel('Density, [kg/m^3]')
plt.ylabel('Velocity for L/D Max, [m/s]')
plt.grid(True)
plt.title(data_srings[0])
# Display the plot
plt.show()

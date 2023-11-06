import numpy as np
from sklearn.datasets import load_iris

# Load the Iris dataset
iris = load_iris()
X = iris.data
y = iris.target

# Calculate the class means
class_means = np.array([X[y == i].mean(axis=0) for i in range(3)])

# Initialize scatter matrices
within_class_scatter = np.zeros((4, 4))
between_class_scatter = np.zeros((4, 4))

# Calculate within-class scatter and between-class scatter
for i in range(3):
    class_samples = X[y == i]
    diff_from_mean = class_samples - class_means[i]
    within_class_scatter += np.dot(diff_from_mean.T, diff_from_mean)
    between_class_scatter += len(class_samples) * np.outer(class_means[i] - X.mean(axis=0), class_means[i] - X.mean(axis=0))

# Calculate total scatter
total_scatter = within_class_scatter + between_class_scatter

# Print the scatter matrices
print("Within-Class Scatter Matrix:\n", within_class_scatter)
print("\nBetween-Class Scatter Matrix:\n", between_class_scatter)
print("\nTotal Scatter Matrix:\n", total_scatter)

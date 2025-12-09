# Topic: Feature normalization (mean 0, variance 1)

import numpy as np

def normalize_features(X):
    X = np.array(X, dtype=float)
    mean = X.mean(axis=0)
    std = X.std(axis=0, ddof=1)
    std[std==0] = 1.0
    return (X - mean) / std

if __name__ == '__main__':
    X = [[1,2],[3,4],[5,6]]
    print('Normalized:\n', normalize_features(X))

# Time Complexity: O(n*d)
# Space Complexity: O(n*d)

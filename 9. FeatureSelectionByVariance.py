# Topic: Feature selection by variance threshold

import numpy as np

def select_by_variance(X, thresh):
    X = np.array(X, dtype=float)
    var = X.var(axis=0, ddof=1)
    return np.where(var >= thresh)[0].tolist()

if __name__ == '__main__':
    X = np.array([[1,2,3],[2,4,6],[3,6,9]])
    print('Kept indices:', select_by_variance(X,1.0))

# Time Complexity: O(n*d)
# Space Complexity: O(d)

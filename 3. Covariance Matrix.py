# Topic: Compute covariance matrix manually using nested loops

import numpy as np

def covariance_matrix(X):
    X = np.array(X, dtype=float)
    n = X.shape[0]
    mean = np.mean(X, axis=0)
    Xc = X - mean
    cov = (Xc.T @ Xc) / (n-1)
    return cov

if __name__ == '__main__':
    X = [[1,2],[3,4],[5,6]]
    print('Covariance:\n', covariance_matrix(X))

# Time Complexity: O(n*d^2)
# Space Complexity: O(d^2)

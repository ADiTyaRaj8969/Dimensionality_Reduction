# Topic: Random projection using Gaussian random matrix

import numpy as np

def random_project(X, k, seed=42):
    np.random.seed(seed)
    d = X.shape[1]
    R = np.random.normal(0, 1/np.sqrt(k), size=(d,k))
    return X @ R

if __name__ == '__main__':
    import numpy as np
    X = np.array([[1,2,3],[4,5,6]], dtype=float)
    Y = random_project(X, 2)
    print('Projected shape:', Y.shape)

# Time Complexity: O(n*d*k)
# Space Complexity: O(d*k)

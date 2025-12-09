# Topic: PCA Implementation using numpy (full PCA for arbitrary dims)

import numpy as np

def pca(X, k=None):
    # X: samples x features
    Xc = X - np.mean(X, axis=0)
    cov = np.cov(Xc, rowvar=False)
    evals, evecs = np.linalg.eigh(cov)
    idx = np.argsort(evals)[::-1]
    evals = evals[idx]
    evecs = evecs[:,idx]
    if k is None: k = X.shape[1]
    return evals[:k], evecs[:,:k]

if __name__ == '__main__':
    data = np.array([[2.5,2.4],[0.5,0.7],[2.2,2.9],[1.9,2.2],[3.1,3.0],[2.3,2.7],[2,1.6],[1,1.1],[1.5,1.6],[1.1,0.9]])
    evals, evecs = pca(data, k=2)
    print('Eigenvalues:', evals)
    print('Eigenvectors:\n', evecs)

# Time Complexity: O(d^3) for eigendecomposition (d=features) or O(n*d^2) for covariance
# Space Complexity: O(d^2)

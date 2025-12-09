# Topic: SVD Decomposition using numpy.linalg.svd and reconstruct using top-k

import numpy as np

def svd_reconstruct(A, k):
    U, S, Vt = np.linalg.svd(A, full_matrices=False)
    S_k = np.diag(S[:k])
    Arec = U[:,:k] @ S_k @ Vt[:k,:]
    return Arec, S

if __name__ == '__main__':
    A = np.array([[1,2],[3,4],[5,6]], dtype=float)
    Arec, S = svd_reconstruct(A, k=1)
    print('Singular values:', S)
    print('Reconstructed with k=1:\n', Arec)

# Time Complexity: O(min(m,n)^2 * max(m,n))
# Space Complexity: O(m*n)

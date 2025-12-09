# Topic: Data compression via PCA — compress and reconstruct small image using numpy SVD

import numpy as np

def compress_image_pca(img, k):
    # img: H x W grayscale
    U, S, Vt = np.linalg.svd(img, full_matrices=False)
    S_k = np.diag(S[:k])
    rec = U[:,:k] @ S_k @ Vt[:k,:]
    err = np.linalg.norm(img - rec)
    return rec, err

if __name__ == '__main__':
    img = np.array([[1,2,3],[4,5,6],[7,8,9]], dtype=float)
    rec, err = compress_image_pca(img, k=1)
    print('Reconstruction error (k=1):', err)

# Time Complexity: O(min(H,W)^2 * max(H,W))
# Space Complexity: O(H*W)

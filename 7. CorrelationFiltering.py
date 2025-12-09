# Topic: Correlation filtering — remove features with correlation above threshold

import numpy as np

def filter_correlation(X, thresh):
    X = np.array(X, dtype=float)
    corr = np.corrcoef(X, rowvar=False)
    d = corr.shape[0]
    keep = np.ones(d, dtype=bool)
    for i in range(d):
        for j in range(i+1, d):
            if abs(corr[i,j]) > thresh:
                keep[j] = False
    return np.where(keep)[0].tolist()

if __name__ == '__main__':
    X = [[1,2,3],[2,4,6],[3,6,9]]
    print('Kept features:', filter_correlation(X,0.9))

# Time Complexity: O(n*d^2)
# Space Complexity: O(d^2)

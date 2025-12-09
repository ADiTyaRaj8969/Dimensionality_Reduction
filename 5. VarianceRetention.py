# Topic: Calculate variance retained after reducing dimensions using top k eigenvalues

import numpy as np

def variance_retained(eigenvals, k):
    eigenvals = np.array(eigenvals)
    total = eigenvals.sum()
    return eigenvals[:k].sum() / total

if __name__ == '__main__':
    print('Variance retained by k=1:', variance_retained([5.0,1.5,0.3],1))

# Time Complexity: O(n)
# Space Complexity: O(1)

// Topic: SVD Decomposition using Eigen library (note: requires Eigen and linking)
// This file demonstrates usage; Eigen must be available to compile.
#include <bits/stdc++.h>
#if __has_include(<Eigen/Dense>)
#include <Eigen/Dense>
using namespace Eigen;
int main()
{
    MatrixXd A(3, 2);
    A << 1, 2, 3, 4, 5, 6;  // 3x2 matrix
    JacobiSVD<MatrixXd> svd(A, ComputeThinU | ComputeThinV);
    cout << "Singular values:\n" << svd.singularValues() << '\n';
    // reconstruct using top k
    int k = 1;
    MatrixXd U = svd.matrixU().leftCols(k);
    MatrixXd V = svd.matrixV().leftCols(k);
    VectorXd S = svd.singularValues().head(k);
    MatrixXd Arec = U * S.asDiagonal() * V.transpose();
    cout << "Reconstructed:\n" << Arec << '\n';
    return 0;
}
#else
int main()
{
    std::cout << "Eigen not installed. To use this file, install Eigen and compile accordingly."
              << std::endl;
    return 0;
}
#endif

// Time Complexity: O(min(m,n)^2 * max(m,n)) depending on implementation
// Space Complexity: O(m*n)

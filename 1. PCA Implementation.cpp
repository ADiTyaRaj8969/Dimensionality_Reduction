// Topic: PCA Implementation (2D analytic eigen decomposition demo)
// Note: This demo computes PCA for 2D datasets by computing covariance matrix and solving quadratic
#include <bits/stdc++.h>
using namespace std;

pair<vector<double>, vector<vector<double>>> pca2d(const vector<pair<double, double>>& data)
{
    int n = data.size();
    double meanx = 0, meany = 0;
    for (auto& p : data)
    {
        meanx += p.first;
        meany += p.second;
    }
    meanx /= n;
    meany /= n;
    double sxx = 0, syy = 0, sxy = 0;
    for (auto& p : data)
    {
        double x = p.first - meanx, y = p.second - meany;
        sxx += x * x;
        syy += y * y;
        sxy += x * y;
    }
    sxx /= (n - 1);
    syy /= (n - 1);
    sxy /= (n - 1);
    // covariance matrix [[sxx, sxy],[sxy, syy]]; eigenvalues via quadratic formula
    double trace = sxx + syy;
    double det = sxx * syy - sxy * sxy;
    double disc = sqrt(max(0.0, trace * trace - 4 * det));
    double lambda1 = (trace + disc) / 2.0;
    double lambda2 = (trace - disc) / 2.0;
    // eigenvector for lambda1: (sxy, lambda1 - sxx) or (lambda1 - syy, sxy)
    vector<double> eig1 = {sxy, lambda1 - sxx};
    double norm = hypot(eig1[0], eig1[1]);
    if (norm == 0)
        eig1 = {1, 0};
    else
    {
        eig1[0] /= norm;
        eig1[1] /= norm;
    }
    vector<double> eig2 = {-eig1[1], eig1[0]};
    return {{lambda1, lambda2}, {eig1, eig2}};
}

int main()
{
    vector<pair<double, double>> data = {{2.5, 2.4}, {0.5, 0.7}, {2.2, 2.9}, {1.9, 2.2},
                                         {3.1, 3.0}, {2.3, 2.7}, {2, 1.6},   {1, 1.1},
                                         {1.5, 1.6}, {1.1, 0.9}};
    auto res = pca2d(data);
    cout << "Eigenvalues: " << res.first[0] << ", " << res.first[1] << '\n';
    cout << "Eigenvector1: (" << res.second[0][0] << "," << res.second[0][1] << ")\n";
    cout << "Eigenvector2: (" << res.second[1][0] << "," << res.second[1][1] << ")\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)

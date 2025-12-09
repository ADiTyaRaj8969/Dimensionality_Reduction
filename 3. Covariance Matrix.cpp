// Topic: Compute covariance matrix manually using nested loops
#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> covarianceMatrix(const vector<vector<double>>& X)
{
    int n = X.size();
    if (n == 0)
        return {};
    int d = X[0].size();
    vector<double> mean(d, 0);
    for (auto& row : X)
        for (int j = 0; j < d; ++j) mean[j] += row[j];
    for (int j = 0; j < d; ++j) mean[j] /= n;
    vector<vector<double>> cov(d, vector<double>(d, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int a = 0; a < d; ++a)
            for (int b = 0; b < d; ++b) cov[a][b] += (X[i][a] - mean[a]) * (X[i][b] - mean[b]);
    }
    for (int a = 0; a < d; ++a)
        for (int b = 0; b < d; ++b) cov[a][b] /= (n - 1);
    return cov;
}

int main()
{
    vector<vector<double>> X = {{1, 2}, {3, 4}, {5, 6}};
    auto cov = covarianceMatrix(X);
    cout << "Covariance:\n";
    for (auto& row : cov)
    {
        for (double v : row) cout << v << " ";
        cout << "\n";
    }
    return 0;
}

// Time Complexity: O(n*d^2)
// Space Complexity: O(d^2)

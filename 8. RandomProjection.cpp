// Topic: Random projection using Gaussian random matrix
#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> randomProject(const vector<vector<double>>& X, int k)
{
    int d = X[0].size();
    int n = X.size();
    std::mt19937 gen(42);
    std::normal_distribution<> dist(0, 1.0 / sqrt(k));
    vector<vector<double>> R(d, vector<double>(k));
    for (int i = 0; i < d; ++i)
        for (int j = 0; j < k; ++j) R[i][j] = dist(gen);
    vector<vector<double>> Y(n, vector<double>(k, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j)
            for (int t = 0; t < k; ++t) Y[i][t] += X[i][j] * R[j][t];
    return Y;
}

int main()
{
    vector<vector<double>> X = {{1, 2, 3}, {4, 5, 6}};
    auto Y = randomProject(X, 2);
    cout << "Projected size: " << Y.size() << " x " << Y[0].size() << '\n';
    return 0;
}

// Time Complexity: O(n*d*k)
// Space Complexity: O(d*k)

// Topic: Feature selection by variance threshold
#include <bits/stdc++.h>
using namespace std;

vector<int> selectByVariance(const vector<vector<double>>& X, double thresh)
{
    int n = X.size();
    int d = X[0].size();
    vector<double> var(d, 0), mean(d, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j) mean[j] += X[i][j];
    for (int j = 0; j < d; ++j) mean[j] /= n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j) var[j] += (X[i][j] - mean[j]) * (X[i][j] - mean[j]);
    for (int j = 0; j < d; ++j) var[j] /= (n - 1);
    vector<int> keep;
    for (int j = 0; j < d; ++j)
        if (var[j] >= thresh)
            keep.push_back(j);
    return keep;
}

int main()
{
    vector<vector<double>> X = {{1, 2, 3}, {2, 4, 6}, {3, 6, 9}};
    auto idx = selectByVariance(X, 1.0);
    cout << "Kept indices:";
    for (int i : idx) cout << " " << i;
    cout << "\n";
    return 0;
}

// Time Complexity: O(n*d)
// Space Complexity: O(d)

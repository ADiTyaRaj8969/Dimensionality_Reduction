// Topic: Correlation filtering — remove features with correlation above threshold
#include <bits/stdc++.h>
using namespace std;

vector<int> filterCorrelation(const vector<vector<double>>& X, double thresh)
{
    int d = X[0].size();
    int n = X.size();
    vector<double> mean(d, 0), stdv(d, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j) mean[j] += X[i][j];
    for (int j = 0; j < d; ++j) mean[j] /= n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j) stdv[j] += (X[i][j] - mean[j]) * (X[i][j] - mean[j]);
    for (int j = 0; j < d; ++j)
    {
        stdv[j] = sqrt(stdv[j] / (n - 1));
        if (stdv[j] == 0)
            stdv[j] = 1;
    }
    vector<vector<double>> corr(d, vector<double>(d, 0));
    for (int a = 0; a < d; ++a)
        for (int b = 0; b < d; ++b)
        {
            double c = 0;
            for (int i = 0; i < n; ++i) c += ((X[i][a] - mean[a]) * (X[i][b] - mean[b]));
            c /= ((n - 1) * stdv[a] * stdv[b]);
            corr[a][b] = c;
        }
    vector<int> keep(d, 1);
    for (int i = 0; i < d; ++i)
        for (int j = i + 1; j < d; ++j)
            if (fabs(corr[i][j]) > thresh)
                keep[j] = 0;
    vector<int> indices;
    for (int i = 0; i < d; ++i)
        if (keep[i])
            indices.push_back(i);
    return indices;
}

int main()
{
    vector<vector<double>> X = {{1, 2, 3}, {2, 4, 6}, {3, 6, 9}};
    double thresh = 0.9;
    auto idx = filterCorrelation(X, thresh);
    cout << "Kept features indices:";
    for (int i : idx) cout << " " << i;
    cout << "\n";
    return 0;
}

// Time Complexity: O(n*d^2)
// Space Complexity: O(d^2)

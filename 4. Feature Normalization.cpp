// Topic: Feature normalization (mean 0, variance 1)
#include <bits/stdc++.h>

using namespace std;

// Normalize features of matrix X (n samples x d features) in-place and return the result.
// Each feature/column will have mean ~= 0 and standard deviation ~= 1 (using sample stddev).
// Safety: if a feature has zero variance, it is left unchanged (stddev treated as 1).
vector<vector<double>> normalizeFeatures(vector<vector<double>> X)
{
    if (X.empty() || X[0].empty())
        return X;

    const size_t n = X.size();
    const size_t d = X[0].size();

    vector<double> mean(d, 0.0);
    vector<double> var(d, 0.0);

    // Compute means
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < d; ++j)
        {
            mean[j] += X[i][j];
        }
    }
    for (size_t j = 0; j < d; ++j) mean[j] /= static_cast<double>(n);

    // Compute (unnormalized) variance sums
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < d; ++j)
        {
            double diff = X[i][j] - mean[j];
            var[j] += diff * diff;
        }
    }

    // Convert to sample standard deviation (ddof=1). If n==1, fall back to 1.0 to avoid
    // div-by-zero.
    for (size_t j = 0; j < d; ++j)
    {
        if (n > 1)
            var[j] = sqrt(var[j] / static_cast<double>(n - 1));
        else
            var[j] = 1.0;
        if (var[j] == 0.0)
            var[j] = 1.0;  // avoid division by zero
    }

    // Normalize
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < d; ++j)
        {
            X[i][j] = (X[i][j] - mean[j]) / var[j];
        }
    }

    return X;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<double>> X = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
    auto Y = normalizeFeatures(X);

    cout << "Normalized:\n";
    cout << fixed << setprecision(6);
    for (const auto& row : Y)
    {
        for (double v : row) cout << v << ' ';
        cout << '\n';
    }

    return 0;
}

// Time Complexity: O(n * d)
// Space Complexity: O(d) additional

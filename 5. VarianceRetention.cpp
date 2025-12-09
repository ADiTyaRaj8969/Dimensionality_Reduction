// Topic: Calculate variance retained after reducing dimensions using top k eigenvalues
#include <bits/stdc++.h>
using namespace std;

double varianceRetained(const vector<double>& eigenvals, int k)
{
    double total = 0;
    for (double v : eigenvals) total += v;
    double top = 0;
    for (int i = 0; i < k && i < eigenvals.size(); ++i) top += eigenvals[i];
    return top / total;
}

int main()
{
    vector<double> evals = {5.0, 1.5, 0.3};
    cout << "Variance retained by k=1: " << varianceRetained(evals, 1) << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubsetSumNoThreeConsecutive(const vector<int>& a, int n) {
    if (n == 0) return 0;
    if (n == 1) return a[0];
    if (n == 2) return a[0] + a[1];

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = a[0];
    dp[2] = a[0] + a[1];

    for (int i = 3; i <= n; i++) {
        dp[i] = max({dp[i - 1], dp[i - 2] + a[i - 1], dp[i - 3] + a[i - 2] + a[i - 1]});
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << maxSubsetSumNoThreeConsecutive(a, n) << endl;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX_N = 1001;
long long cost[MAX_N][MAX_N];
long long dp[MAX_N][MAX_N];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = LLONG_MAX;
        }
    }

    dp[1][1] = cost[1][1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                continue;
            if (cost[i][j] == 0)
                continue; // ko di duoc, next

            if (i > 1 && dp[i - 1][j] != LLONG_MAX)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost[i][j]);
            if (j > 1 && dp[i][j - 1] != LLONG_MAX)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + cost[i][j]);
            if (i > 1 && j > 1 && dp[i - 1][j - 1] != LLONG_MAX)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + cost[i][j]);
        }
    }

    if (dp[n][m] == LLONG_MAX)
    {
        cout << "-1\n";
    }
    else
    {
        cout << dp[n][m] << "\n";
    }

    return 0;
}

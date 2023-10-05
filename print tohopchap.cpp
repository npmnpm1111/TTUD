#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
const int maxm = 20;
int n;
int m;
int x[maxn];
bool marked[maxn] = {false};

void print_sol(int A[maxn])
{
    for (int i = 1; i <= m; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Try(int k)
{
    for (int i = 1; i <= n; i++)
    {
        x[k] = i;
        if (!marked[i] && x[k] > x[k - 1])
        {
            marked[i] = true;
            if (k == m)
                print_sol(x);
            else
                Try(k + 1);
            marked[i] = false;
        }
    }
}

int main()
{
    cin >> m;
    cin >> n;
    x[0] = 0;
    Try(1);
    return 0;
}

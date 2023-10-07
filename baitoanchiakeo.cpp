#include <bits/stdc++.h>
using namespace std;
const int maxm = 20;
const int maxn = 20;
int m;
int n;
int x[maxn];

void print_sol(int A[maxn])
{
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Try(int k)
{
    for (int i = 1; i <= (1 + (m - n)); i++)
    {
        if (k != n)
        {
            x[k] = i;
            Try(k + 1);
        }
        else
        {
            x[k] = 0;
            for (int i = 1; i <= (n - 1); i++)
            {
                x[k] = x[k] + x[i];
            }
            x[k] = m - x[k];
            print_sol(x);
            break;
        }
    }
}

int main()
{
    cin >> m;
    cin >> n;
    Try(1);
    return 0;
}

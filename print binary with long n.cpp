#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int n;
int x[maxn];

void print_sol(int A[maxn])
{
    for (int i = 1; i <= n; i++)
    {
        cout << A[i];
    }
    cout << endl;
}

void Try(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        x[k] = i;
        if (k == n)
            print_sol(x);
        else
            Try(k + 1);
    }
}

int main()
{
    cin >> n;
    Try(1);
    return 0;
}

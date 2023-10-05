#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
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
bool isUsed(int val, int k)
{
    for (int i = 1; i < k; i++)
    {
        if (x[i] == val)
            return true;
    }
    return false;
}

void Try(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (!isUsed(i, k))
        {
            x[k] = i;
            if (k == n)
                print_sol(x);
            else
                Try(k + 1);
        }
    }
}

int main()
{
    x[0] = 0;
    cin >> n;
    Try(1);
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

int n, M;
vector<int> a;
vector<int> x;
int sol = 0;

bool isInteger(double num)
{
    return floor(num) == num;
}

void print_sol(const vector<int> &x)
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}



void Try(int k)
{
    for (int i = 1; i <= M; i++)
    {
        if (k != n - 1)
        {
            x[k] = i;
            Try(k + 1);
        }
        else
        {
            int S = 0;
            for (int j = 0; j < n - 1; j++)
            {
                S += a[j] * x[j];
            }

            if (isInteger((M - S) / static_cast<double>(a[k])) && (M - S) / static_cast<double>(a[k]) > 0)
            {
                x[k] = (M - S) / static_cast<double>(a[k]);
                print_sol(x);
                // sol++;
                break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> M;

    a.resize(n);
    x.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Try(0);
    // cout << sol << endl;
}

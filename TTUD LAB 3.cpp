#include <bits/stdc++.h>
#include <sstream>
#include <set>

using namespace std;

int n, m, a, b;
vector<int> A;
multiset<int> B;

// int MINS(int i, int j)
// {
// }
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        A.push_back(n);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        for (int i = a; i < b; i++)
        {
            B.insert(A[i]);
        }
    }
}

#include <iostream>
#include <queue>
using namespace std;

int n, m, r, c;

const int nmax = 999;
const int mmax = 999;
int A[nmax][mmax];
bool mark[nmax][mmax] = {false};
int dist[nmax][mmax] = {0};
queue<int> q;

int main()
{
    cin >> n >> m >> r >> c;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> A[i][j];
    }
    q.push(A[r][c]);
    int reset = 1;
    while (q.empty() != true)
    {
        if (A[r][c] == 0 && ((r == 0) || (c == 0) || (r == n - 1) || (c == m - 1)))
        {
            mark[r][c] = true;
            dist[r][c]++;
            q.pop();
        }
        else
        {
            q.push(A[r - 1][c]);
            q.push(A[r][c + 1]);
            q.push(A[r + 1][c]);
            q.push(A[r][c - 1]);
            mark[r][c] = true;
            q.pop();
        }
        if (reset == 1)
        {
            r = r - 1;
            reset++;
        }
        if (reset == 2)
        {
            r = r + 1;
            c = c + 1;
            reset++;
        }
        if (reset == 3)
        {
            r = r + 1;
            c = c - 1;
            reset++;
        }
        if (reset == 4)
        {
            r = r - 1;
            c = c - 1;
            reset++;
        }
        if (reset == 5)
            reset = 1;
    }
}
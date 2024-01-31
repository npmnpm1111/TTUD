#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> M;

int main()
{
    int count = 0;
    cin >> n;
    M.resize(n); // Khởi tạo kích thước cho vector
    cin >> M[0]; 

    for (int i = 1; i < n; i++)
    {
        cin >> M[i];
        m = M[i];
        for (auto &M : M) 
        {
            if (m < M)
                count++;
        }
    }
    cout << count << endl;

    return 0;
}

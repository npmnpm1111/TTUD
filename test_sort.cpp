#include <iostream>
#include <algorithm>
using namespace std;
int main()

{
    int a[] = {4, 1, 8, 3, 9, 11, 20, 13};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }

    return 0;
}
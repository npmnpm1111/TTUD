#include <iostream>
#include <algorithm>
using namespace std;

int P;
int binarySearch(int arr[], int left, int right, int value)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int n;

    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A, A + n);
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            int sum = A[i] + A[j];
            if (binarySearch(A, j + 1, n, sum) != -1)
                P++;
        }
    }
    cout << P;
}

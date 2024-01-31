#include <iostream>
using namespace std;

const int maxn = 20;
int n, year;
int numbers[maxn];
bool marked[maxn] = {false};
int count = 0;
int sum = 0;
void Try(int k)
{
    if (sum >= year)
        count++;

    for (int i = k; i <= n; i++)
    {
        if (!marked[i])
        {
            marked[i] = true;
            sum = sum + numbers[i];
            Try(i + 1);
            marked[i] = false;
            sum = sum - numbers[i];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> numbers[i];
    }
    cin >> year;

    Try(1);
    cout << count << endl;

    return 0;
}

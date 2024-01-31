#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int n, num;
int main()
{
    map<int, int> set;
    cin >> n;
    int value;
    string line;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (set.find(num) == set.end())
            set.insert({num, 1});
        else
            set[num]++;
    }
    while (cin >> line && line != "*")
    {
        if (line == "insert")
        {
            cin >> value;
            if (set.find(value) == set.end())
                set.insert({value, 1});
            else
                set[value]++;
        }
        else
        {
            auto max = *set.rbegin();
            cout << max.first << endl;
            set[max.first]--;
            if (set[max.first] == 0)
                set.erase(max.first);
        }
    }
}

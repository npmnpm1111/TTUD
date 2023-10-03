#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int a, b, c;
    a = b = c = 0;
    bool yes = true;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            a++;
        else if (s[i] == ')')
            a--;
        else if (s[i] == '{')
            b++;
        else if (s[i] == '}')
            b--;
        else if (s[i] == '[')
            c++;
        else if (s[i] == ']')
            c--;

        if (a < 0 || b < 0 || c < 0)
        {
            yes = false;
            break;
        }
    }
    if (yes && a == 0 && b == 0 && c == 0)
        cout << "1" << endl;
    else
        cout << "0" << endl;
}

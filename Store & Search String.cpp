#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<string> database;
    string line;
    do
    {
        getline(cin, line);
        if (line != "*")
        {
            database.insert(line);
        }
    } while (line != "*");

    do
    {
        getline(cin, line);
        if (line != "***")
        {
            if (line[0] == 'f')
            {
                if (database.find(line.substr(5)) != database.end())
                {
                    cout << '1' << endl;
                }
                else
                {
                    cout << '0' << endl;
                }
            }
            else
            {
                if (database.find(line.substr(7)) != database.end())
                {
                    cout << '0' << endl;
                }
                else
                {
                    database.insert(line.substr(7));
                    cout << '1' << endl;
                }
            }
        }
    } while (line != "***");
}

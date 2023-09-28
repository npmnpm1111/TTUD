#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> database, cmd;
    string line;
    do
    {
        getline(cin, line);
        if (line != "*")
        {
            database.push_back(line);
        }
    } while (line != "*");

    do
    {
        getline(cin, line);
        if (line != "***")
        {
            cmd.push_back(line);
        }
    } while (line != "***");

    for (unsigned long long i = 0; i < cmd.size(); i++)
    {
        if (cmd[i][0] == 'f')
        {
            if (find(database.begin(), database.end(), cmd[i].substr(5)) != database.end())
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
            if (find(database.begin(), database.end(), cmd[i].substr(7)) != database.end())
            {
                cout << '0' << endl;
            }
            else
            {
                database.push_back(cmd[i].substr(7));
                cout << '1' << endl;
            }
        }
    }
}

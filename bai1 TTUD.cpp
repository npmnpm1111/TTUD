// CPP
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <string>

int main()
{
    std::unordered_set<std::string> database;
    std::string line;

    while (std::getline(std::cin, line) && line != "*")
    {
        database.insert(line);
    }

    while (std::getline(std::cin, line) && line != "***")
    {
        size_t pos = line.find(' ');
        std::string cmd = line.substr(0, pos);
        std::string key = line.substr(pos + 1);

        if (cmd == "find")
        {
            if (database.find(key) != database.end())
                std::cout << 1 << std::endl;
            else
                std::cout << 0 << std::endl;
        }
        else if (cmd == "insert")
        {
            if (database.find(key) == database.end())
            {
                database.insert(key);
                std::cout << 1 << std::endl;
            }
            else
            {
                std::cout << 0 << std::endl;
            }
        }
    }

    return 0;
}
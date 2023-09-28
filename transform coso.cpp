// CPP
#include <bits/stdc++.h>
#include <iostream>
#include <string>
int main()
{
    int n;
    std::vector<int> c;
    std::cin >> n;
    if (n >= 0)
    {
        int d = n;
        do
        {
            c.push_back(d % 2);
            d = d / 2;
        } while (d != 0);
        for (int i = c.size() - 1; i >= 0; i--)
        {
            std::cout << c[i];
        }
    }
    else
        (std::cout << "khong hop le");
}
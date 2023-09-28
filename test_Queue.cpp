#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
class Plane
{ // Tuy_Bien_Priority_Queue_Min
public:
    int fuel;

public:
    Plane(int q) { this->fuel = q; }
    friend ostream &operator<<(ostream &os, const Plane &p)
    {
        os << p.fuel << endl;
        return os;
    }
    bool operator>(const Plane &p) const
    {
        return fuel > p.fuel;
    }
};
typedef priority_queue<Plane, vector<Plane>, greater<Plane>> PQPlane;

int main()
{
    vector<Plane> vP;
    vP.push_back(Plane(4));
    vP.push_back(Plane(7));
    vP.push_back(Plane(3));
    vP.push_back(Plane(9));
    PQPlane PQ(vP.begin(), vP.end());
    while (!PQ.empty())
    {
        cout << PQ.top();
        PQ.pop();
    }
    return 0;
}

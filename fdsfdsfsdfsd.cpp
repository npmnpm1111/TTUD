#include <bits/stdc++.h>
using namespace std;
//freopen("duyhung_13.bairieng.inp","r",stdin);
//freopen("duyhung_13.bairieng.out","w",stdout);
double n;
double t,tien=0;
int main(){
	cin>>n>>t;
	for(int i=1;i<=t;i++)
	{
		n+=(double)n*0.01;
	}
	cout << n*1.0;
	
}
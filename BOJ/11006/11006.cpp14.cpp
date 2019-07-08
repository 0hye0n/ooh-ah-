#include <bits/stdc++.h>
using namespace std;
int t, x, y;
int main() 
{
	cin>>t;
	for(int i = 0; i<t; i++)
	{
		cin>>x>>y;
		cout<<(2*y-x)<<" "<<y-(2*y-x)<<endl;
	}
	return 0;
}
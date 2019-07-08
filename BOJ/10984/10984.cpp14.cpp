#include <bits/stdc++.h>
using namespace std;
int n;
int main() 
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout<<fixed;
	cout.precision(1);
	cin>>n;
	while(n--)
	{
		int t, num = 0;
		double score=0;
		cin>>t;
		for(int i = 0; i<t; i++)
		{
			int temp1;double temp2;
			cin>>temp1>>temp2;
			num+=temp1;score+=temp1*temp2;
		}
		cout<<num<<" "<<(double)score/num<<"\n";
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int t, n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		lld res = 1;
		cin>>n;
		for(int i = 1; i<=n; i++)
		{
			res*=i;
			while(1)
			{
				if(res%10==0)res/=10;
				else break;
			}
			res%=1000000000;
		}
		cout<<res%10<<"\n";	
	}
	
	return 0;	
}
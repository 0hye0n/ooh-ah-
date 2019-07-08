#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int n;
lld res = 1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
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
	return 0;	
}
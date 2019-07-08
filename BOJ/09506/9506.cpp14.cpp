#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n;
int res[50009];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	while(n!=-1)
	{
		int pos=0;
		for(int i = 1; i*i<=n; i++)
		{
			if(i*i==n){res[pos]=i;pos++;}
			else if(n%i==0){
				res[pos]=i;pos++;
				res[pos]=n/i;pos++;
			} 
		}
		lld sum=0;
		sort(res, res+pos);
		for(int i = 0; i<pos-1; i++)sum+=res[i];
		if(sum==n){
			cout<<n<<" = ";
			for(int i = 0; i<pos-1; i++)
			{
				if(i<pos-2)cout<<res[i]<<" + ";
				else cout<<res[i]<<"\n";
			}
		}
		else cout<<n<<" is NOT perfect.\n";
		cin>>n;
	}
	
	return 0;
}
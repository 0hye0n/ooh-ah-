#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n;
vector <int> prime;
bool check[1000009];

void makeprime()
{
	check[0]  = true;
	check[1]  = true;
	for(int i = 2; i<=1000000; i++)
	{
		if(check[i])continue;
		for(int j = 2; i*j<=1000000; j++)check[i*j]=true;
	}
	for(int i = 2; i<=1000000; i++)if(!check[i])prime.emplace_back(i);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	makeprime();
	int size = prime.size();
	cin>>n;
	while(n)
	{
		bool state = false;
		for(int i = 1; prime[i]<n; i++)
		{
			if(!check[n-prime[i]]){cout<<n<<" = "<<prime[i]<<" + "<<n-prime[i]<<"\n";state = true;break;}
		}
		if(!state)cout<<"Goldbach's conjecture is wrong.\n";
		cin>>n;
	}
	return 0;
}
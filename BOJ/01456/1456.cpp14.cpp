#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
bool check[10000009];
vector <lld> prime;
lld a, b, cnt=0;
void getprime()
{
	for(lld i = 2; i<=10000000; i++)
	{
		if(check[i])continue;
		for(lld j = 2; j*i<=10000000; j++)check[j*i]=true;
	}
	for(lld i = 2; i<=10000000; i++){if(!check[i])prime.push_back(i);}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>b;
	getprime();
	lld size = prime.size();
	//cout<<size<<"\n";
	for(int i = 0; i<size; i++)
	{
		lld temp = prime[i]*prime[i];
		while(temp<=b){
			if(temp>=a)cnt++;
			if(log(b)<log(temp)+log(prime[i]))break;
			temp*=prime[i];
		}
	}
	cout<<cnt;
	
	return 0;
}
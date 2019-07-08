#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int t, data, sum=0, tnum[3], size;
bool flag = false;
vector <int> prime; 
inline void getprime(const int num)
{
	int temp[num+1];temp[0]=0;temp[1]=0;
	for(int i = 2; i<=num; i++) temp[i]=i;
	for(int i = 2; i<=num; i++){
		if(temp[i]==0)continue;
		for(int j = i+i; j<=num; j+=i)temp[j]=0;
	}
	for(int i = 2; i<=num; i++)
		if(temp[i]!=0)prime.emplace_back(temp[i]);
	return;
}
inline void solve(int pos){
	if(flag)return;
	if(pos==3)
	{
		if(tnum[0]+tnum[1]+tnum[2]==data)
		{
			sort(tnum, tnum+3);
			cout<<tnum[0]<<" "<<tnum[1]<<" "<<tnum[2]<<"\n"; 
			flag = true;
			return;
		}
		return;
	}
	for(int i = 0; i<size; i++)
	{
		if(flag)return;
		tnum[pos] = prime[i];
		solve(pos+1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	getprime(1000);size = prime.size();
	cin>>t;
	while(t--)
	{
		cin>>data;
		solve(0);
		if(!flag)cout<<"0\n";
		flag = false;
	}
	return 0;
}
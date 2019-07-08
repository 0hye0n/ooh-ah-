#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
lld data[2], sum=0;
inline void solve(){
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>data[0]>>data[1];
	sort(data, data+2);
	lld n = data[1]-data[0]+1;
	sum = (2*data[0]+(n-1))*n/2;
	cout<<sum;
	return 0;
}
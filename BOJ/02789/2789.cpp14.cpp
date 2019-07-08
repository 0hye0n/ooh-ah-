#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
string data;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>data;
	int len = data.length();
	for(int i = 0; i<len; i++)
	{
		if(data[i]=='C'||data[i]=='A'||data[i]=='M'||data[i]=='B'||data[i]=='R'||data[i]=='I'||data[i]=='D'||data[i]=='G'||data[i]=='E')continue;
		else cout<<data[i];
	}
	return 0;
}
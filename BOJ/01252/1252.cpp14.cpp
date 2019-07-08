#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
char data1[89], data2[89];
int result[89];
int a[89], b[89];
bool c1=false, c2=false;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>data1>>data2;
	int len1 = strlen(data1), len2 = strlen(data2);
	reverse(data1, data1+len1);
	reverse(data2, data2+len2);
	for(int i = 85; i>0; i--)if(data1[i]=='1'){len1=i+1;c1=true;break;}
	for(int i = 85; i>0; i--)if(data2[i]=='1'){len2=i+1;c2=true;break;}
	if(!c1)len1 = 1;
	if(!c2)len2 = 1;
	int mx = max(len1, len2);
	for(int i = 0; i<mx; i++)
	{
		if(i<len1)a[i] = data1[i]=='0'?0:1;
		if(i<len2)b[i] = data2[i]=='0'?0:1;
	}
	for(int i = 0; i<mx; i++)result[i] = a[i]+b[i];
	for(int i = 0; i<mx; i++)
	{
		result[i+1]+=result[i]/2;
		result[i]%=2;
	} 
	for(int i = mx; result[i]!=0; i++)
	{
		result[i+1] = result[i]/2;
		result[i] %= 2; 
		mx++;
	}
	reverse(result, result+mx);
	for(int i = 0; i<mx; i++)cout<<result[i];

	return 0;
}
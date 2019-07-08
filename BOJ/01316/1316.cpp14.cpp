#include <bits/stdc++.h>
using namespace std;
int t, cnt=0;
bool check[26];
int main() 
{
	scanf("%d", &t);
	while(t--)
	{
		for(int i = 0; i<26; i++)check[i]=false;
		bool haha=false;
		char data[109];int len;
		scanf("%s", data);len = strlen(data);
		for(int i = 1; i<len; i++)
		{
			if(check[data[i]-'a'])haha=true;
			else if(data[i]!=data[i-1])check[data[i-1]-'a']=true;
		}
		if(!haha)cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
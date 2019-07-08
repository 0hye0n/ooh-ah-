#include <bits/stdc++.h>
using namespace std;
char data[1000009];
int cnt[30];
int check = false;
int main() 
{
	scanf("%s", &data);int len = strlen(data);
	for(int i = 0; i<len; i++)
	{
		if(data[i]>='a')cnt[data[i]-'a']++;
		else if(data[i]<'a')cnt[data[i]-'A']++;
	}
	int mx=0;
	for(int i = 1; i<26; i++)
	{
		if(cnt[mx]<cnt[i]){check = false;mx = i;}
		else if(cnt[mx]==cnt[i])check=true;
		}	
	if(check)printf("?\n");
	else printf("%c", mx+65);
	

	return 0;
}
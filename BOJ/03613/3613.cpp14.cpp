#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
char data[109];
bool check = false;
int main()
{
	int diff = 'a'-'A';
	scanf("%s", data);int len = strlen(data);
	
	for(int i = 0; i<len; i++)if(data[i]<='Z'&&data[i]>='A'){check=true;break;}
	if(check){
		int c1 = 0, c2 = 0;
		for(int i = 1; i<len; i++)if(data[i]<='Z'&&data[i]>='A')c1++;
		for(int i = 0; i<len; i++)if(data[i]<='z'&&data[i]>='a')c2++;
		if(c1+c2!=len){printf("Error!");return 0;}
		for(int i = 0; i<len; i++)
		{
			if(data[i]<='Z'&&data[i]>='A')printf("_%c", data[i]+diff);
			else printf("%c", data[i]);
		}
		return 0;
	}

	else{
		int c1=0;
		if(data[0]=='_'||data[len-1]=='_'){printf("Error!");return 0;}
		for(int i = 1; i<len; i++){
			if(data[i]==data[i-1]&&data[i]=='_'){printf("Error!");return 0;}
		}
		int j;
		for(j = 0; j<len; j++)if(data[j]!='_')break;
		for(int i = j; i<len; i++)
		{
			if(data[i]=='_'&&i!=0){if(data[i+1]!='_')data[i+1]-=diff;continue;}
			else cout<<data[i];
		}
		return 0;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
char data[256];
int main() 
{
	while(1)
	{
		gets(data);int len = strlen(data);
		if(len==1&&data[0]=='#')break;
		int cnt = 0;
		for(int i = 0; i<len; i++)if(data[i]=='a'||data[i]=='A'||data[i]=='e'||data[i]=='E'||data[i]=='i'||data[i]=='I'||data[i]=='o'||data[i]=='O'||data[i]=='u'||data[i]=='U')cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
int s;
char data[1009];
int main()
{
	scanf("%d", &s);
	for(int i = 0; i<s; i++)
	{
		scanf(" %[^\n]s", data);
		int len = strlen(data), c=0, v=0;
		for(int j = 0; j<len; j++)
		{
			if(data[j]=='A'||data[j]=='E'||data[j]=='I'||data[j]=='O'||data[j]=='U'||data[j]=='a'||data[j]=='e'||data[j]=='i'||data[j]=='o'||data[j]=='u')v++;
			else if(data[j]!=' ')c++;
		}
		printf("%d %d\n", c, v);
	}
	return 0;
}
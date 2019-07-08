#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char c, data[259];
int d = 'a'-'A';
int main()
{
	scanf("%c %[^\n]s", &c, data);
	int len = strlen(data);
	while(c!='#')
	{
		int cnt = 0;
		for(int i = 0; i<len; i++)if(data[i]==c||data[i]==c-d)cnt++;
		printf("%c %d\n", c, cnt);
		scanf(" %c %[^\n]s", &c, data);
		len = strlen(data);
	}
	return 0;
}
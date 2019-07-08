#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char data[10];
int main()
{
	scanf("%s", data);
	while(!(strlen(data)==1&&data[0]=='0'))
	{
		bool flag = false;
		int len = strlen(data);
		char temp[10];strcpy(temp, data);
		reverse(temp, temp+len);
		for(int i = 0; i<len; i++)if(data[i]!=temp[i]){flag=true;break;}
		printf(flag?"no\n":"yes\n");
		scanf("%s", data);
	}

	return 0;
}
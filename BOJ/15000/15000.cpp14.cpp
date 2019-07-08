#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char data[1000009];
int main()
{
	scanf("%s", data);
	int len = strlen(data);
	for(int i = 0; i<len; i++)data[i] = data[i]-32;
	printf("%s\n", data);

	return 0;
}
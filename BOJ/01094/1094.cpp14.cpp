#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int x, result=0;
int len[] = {64, 32, 16, 8, 4, 2, 1};
int main()
{
	int i = 0;
	scanf("%d", &x);
	while(x>0)
	{
		result += x/len[i];
		x%=len[i];
		i++;
	}
	printf("%d", result);
	return 0;
}
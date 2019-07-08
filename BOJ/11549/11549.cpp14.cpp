#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int t, cnt=0;
int ans[5];
int main()
{
	scanf("%d %d %d %d %d %d", &t, &ans[0], &ans[1], &ans[2], &ans[3], &ans[4]);
	for(int i = 0; i<5; i++)if(t==ans[i])cnt++;
	printf("%d\n", cnt);
	return 0;
}
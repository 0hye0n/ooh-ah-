#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int t, n;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		int sum = 0, temp;
		scanf(" %d", &n);
		for(int i = 0; i<n; i++)
		{
			scanf(" %d", &temp);
			sum+=temp;
		}
		printf("%d\n", sum);
	}
	return 0;
}
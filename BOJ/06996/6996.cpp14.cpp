#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int t;
char a[109], b[109];
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		char temp1[109], temp2[109];
		scanf(" %s %s", a, b);
		strcpy(temp1, a);
		strcpy(temp2, b);
		sort(a, a+strlen(a));
		sort(b, b+strlen(b));
		if(strcmp(a, b)==0) printf("%s & %s are anagrams.\n", temp1, temp2);
		else printf("%s & %s are NOT anagrams.\n", temp1, temp2);
	}
	return 0;
}
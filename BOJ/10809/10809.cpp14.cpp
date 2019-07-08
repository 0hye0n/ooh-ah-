#include <bits/stdc++.h>
using namespace std;
char n[109];
int cnt[26];
int main() {
	for(int i = 0; i<26; i++)
		cnt[i] = -1;
	scanf("%s", &n);
	for(int i = 0 ; i<strlen(n); i++)
	{
		if(cnt[(int)n[i]-97]==-1)
			cnt[(int)n[i]-97] = i;	
	}
	for(int i =0 ; i<26; i++)
		printf("%d ", cnt[i]);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
char n[109];
int cnt[26];
int main() {
	scanf("%s", &n);
	for(int i = 0 ; i<strlen(n); i++)
	{
		cnt[(int)n[i]-97]++;	
	}
	for(int i =0 ; i<26; i++)
		printf("%d ", cnt[i]);
	return 0;
}

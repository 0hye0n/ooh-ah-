#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int cnt[26], mx = 0;
string s;
int main() {
	while (cin>>s) {
		for (int i = 0; i < s.length(); i++)cnt[s[i] - 'a']++;			
		s = "";
	}
	for (int i = 0; i < 26; i++)if (mx < cnt[i])mx = cnt[i];
	for (int i = 0; i < 26; i++)if (cnt[i] == mx)printf("%c", i+'a');
}

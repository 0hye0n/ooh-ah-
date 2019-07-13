#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int mx = -1, cnt[29], n;

int main()
{
	cin>>n;

	for(int i = 0; i < n; i++)
	{
		string temp;cin>>temp;
		cnt[temp[0] - 'a']++;
		mx = max(cnt[temp[0] - 'a'], mx);
	}

	if(mx < 5) cout<<"PREDAJA";
	else
	{
		for(int i = 0; i < 26; i++)
		{
			if(5 <= cnt[i])printf("%c", i + 'a');
		}
	}
	return 0;
}
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

string in;
int cnt[19], mx = -1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>in;
	int size = in.length();
	for(int i = 0; i < size; i++)
	{
		cnt[in[i] - '0']++;
		if(in[i] != '6' && in[i] != '9')mx = max(cnt[in[i] - '0'], mx);
	}
	mx = max(mx, (cnt[6] + cnt[9]) / 2 + (cnt[6] + cnt[9]) % 2);
	cout<<mx;
	return 0;
}
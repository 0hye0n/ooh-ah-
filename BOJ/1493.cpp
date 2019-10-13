#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

long long l, w, h, n, need[29], cube[29], ans = 0;

long long findcube(long long l, long long w, long long h)
{
	long long mn = min<long long>({l, w, h});

	for(long long i = 0, j = 1;; i++, j <<= 1)
	{
		if(mn < j)return i - 1;
	}
}

void solve(long long l, long long w, long long h)
{
	//cout<<l<<" "<<w<<" "<<h<<"\n";
	if(l <= 0 || w <= 0 || h <= 0) return;

	long long val = findcube(l, w, h);
	long long len = 1 << val;
	need[val] += (l / len) * (w / len) * (h / len);

	solve(l % len, (w / len) * len, (h / len) * len);
	solve((l /len) * len, w % len, (h / len) * len);
	solve(l % len, w % len, (h / len) * len);
	solve((l /len) * len, (w / len) * len, h % len);
	solve(l % len, (w / len) * len, h % len);
	solve((l /len) * len, w % len, h % len);
	solve(l % len, w % len, h % len);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>l>>w>>h>>n;

	for(long long i = 0; i < n; i++)
	{
		long long x, y;cin>>x>>y;
		cube[x] += y;
	}

	solve(l, w, h);
	
	long long needpos = 20;
	bool flag = false;
	while(needpos >= 0)
	{
		if(need[needpos] == 0)
		{
			while(!need[needpos])
			{
				needpos--;
				if(needpos == -1)
				{
					flag = true;
					break;	
				}
			} 
		}
		if(flag)break;

		if(need[needpos] > cube[needpos])
		{
			if(needpos == 0)
			{
				cout<<"-1";
				return 0;
			}
			ans += cube[needpos];
			need[needpos] -= cube[needpos];
			need[needpos - 1] += need[needpos] * 8;
			need[needpos] = cube[needpos] = 0;

		}

		else
		{
			ans += need[needpos];
			cube[needpos] -= need[needpos];
			need[needpos] = 0;

		}
	}
	cout<<ans;
	return 0;
}

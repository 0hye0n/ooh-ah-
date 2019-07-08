#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 n, m, data[10], res[10];
bool access[10];

void solve(i32 pos)
{
	if(pos==m)
	{
		for(int i = 0; i<m; i++)cout<<res[i]<<" ";
		cout<<"\n";
		return;
	}
	if(pos==0)
	{
		for(int i = 0; i<n; i++)
		{
			if(data[i]!=res[pos])
			{
				access[i]=true;
				res[pos]=data[i];
				solve(pos+1);
				access[i]=false;
			}
		}	
	}
	else
	{
		for(int i = 0; i<n; i++)
		{
			if(data[i]!=res[pos])
			{
				access[i]=true;
				res[pos]=data[i];
				solve(pos+1);
				access[i]=false;
			}
		}
	}	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(res, -1, sizeof(res));
	cin>>n>>m;
	for(int i = 0; i<n; i++)cin>>data[i];
	sort(data, data+n);
	solve(0);
	return 0;
}
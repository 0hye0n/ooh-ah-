#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 data[9], res[10], sum=0;
bool check[9], flag=false;

void solve(i32 pre, i32 pos)
{
	if(flag)return;
	if(pos==7)
	{
		if(sum==100)
		{
			flag=true;
			for(i32 i = 0; i<7; i++)cout<<res[i]<<"\n";
			return;
		}
		return;
	}
	for(i32 i = 0; i<9; i++)
	{
		if(!check[i]&&pre<i)
		{
			sum+=data[i];
			res[pos]=data[i];
			check[i] = true;
			solve(i, pos+1);
			check[i] = false;
			sum-=data[i];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(i32 i = 0; i<9; i++)cin>>data[i];
	sort(data, data+9);
	solve(-1, 0);
	return 0;
}
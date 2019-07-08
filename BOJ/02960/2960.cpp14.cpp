#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 n, k, cnt=1, ans;
bool check[1009];
vector <i32> prime;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;

	for(i32 i = 2; i<=n; i++)
	{
		for(i32 j = 1;i*j<=n;j++)
		{
			if(cnt==k)ans=i*j;
			if(!check[i*j])
			{
				check[i*j]=true;
				cnt++;
			}		
		}
	}
	cout<<ans;
	return 0;
}
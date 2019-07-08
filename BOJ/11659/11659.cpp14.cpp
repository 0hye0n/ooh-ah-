#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i64 prefix[100009], n, m, sum=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(i32 i = 1; i<=n; i++)
	{
		i64 temp;cin>>temp;
		sum+=temp;
		prefix[i] = sum;
	}
	while(m--)
	{
		i32 s, e;cin>>s>>e;
		cout<<prefix[e]-prefix[s-1]<<"\n";
	}
	return 0;
}
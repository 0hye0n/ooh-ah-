#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 check[6] = {1, 1, 2, 2, 2, 8};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(i32 i = 0; i<6; i++)
	{
		i32 temp;cin>>temp;
		cout<<check[i]-temp<<" ";
	}
	return 0;
}
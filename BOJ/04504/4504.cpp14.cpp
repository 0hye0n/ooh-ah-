#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 n, data;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	cin>>data;
	while(data)
	{
		if(data%n==0)cout<<data<<" is a multiple of "<<n<<".\n";
		else cout<<data<<" is NOT a multiple of "<<n<<".\n";
		cin>>data;
	}
	return 0;
}
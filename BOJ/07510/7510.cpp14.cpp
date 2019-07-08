#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 t, a[3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	i32 i = 0;
	while(t--)
	{
		i++;
		cin>>a[0]>>a[1]>>a[2];
		sort(a, a+3);
		cout<<"Scenario #"<<i<<":\n";
		if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])cout<<"yes\n\n";
		else cout<<"no\n\n";
	}
	return 0;
}
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 e, f, c, ans=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>e>>f>>c;
	i32 tot = e+f;
	while(tot>=c)
	{
		i32 temp = tot/c;
		ans += tot/c;
		tot = temp+tot%c;
	}
	cout<<ans;
	return 0;
}
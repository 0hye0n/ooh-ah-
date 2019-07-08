#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define push_back pb
#define emplace_back eb
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef short i8;
typedef int i32;
typedef long long i64;
typedef unsigned short ui8;
typedef unsigned int ui32;
typedef unsigned long long ui64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;

i32 t, a[20009], b[20009], ans = 0;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		bool flag = false;
		i32 n, m;cin>>n>>m;
		for(i32 i = 0; i < n; i++)cin>>a[i];
		for(i32 i = 0; i < m; i++)cin>>b[i];
		sort(b, b+m);
		for(register int i = 0; i < n; i++)
		{
			for(register int j = 0; j < m; j++)
			{
				if(a[i]<=b[j])
				{
					flag = true;
					ans += j;
					break;
				}
			}
			if(!flag) ans += m;
			flag = false;
		}
		cout<<ans<<"\n";
		ans = 0;

	}
	return 0;
}
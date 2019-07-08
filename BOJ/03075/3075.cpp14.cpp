#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
//#define push_back pb
//#define emplace_back eb
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

i64 t, n, p, q, sum[109], d[109][109], per[109];
bool check[109];

void solve()
{
	for(i32 i = 1; i <= p; i++)
		for(i32 j = 1; j <= p; j++){
			if(d[j][i]==2e9)continue;
			for(i32 k = 1; k <= p; k++)
			{
				if(d[i][k]==2e9)continue;
				if(d[j][k] > d[j][i] + d[i][k])
				{
					d[j][k] = d[j][i] + d[i][k];
				}
			}
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		memset(check, false, sizeof(check));
		for(i32 i = 0; i < 109; i++)
			for(i32 j = 0; j < 109; j++)
				d[i][j] = 2e9;
		for(i32 i = 0; i < 109; i++) sum[i] = 0L;
		for(i32 i = 0; i < 109; i++) d[i][i] = 0L;

		cin>>n>>p>>q;

		for(i32 i = 0; i < n; i++)cin>>per[i];

		for(i32 i = 0; i < q; i++)
		{
			i64 x, y, z;cin>>x>>y>>z;
			d[x][y] = min(z, d[x][y]);
			d[y][x] = min(z, d[x][y]);
		}

		solve();

		for(i32 i = 1; i <= p; i++)
		{
			for(i32 j = 0; j < n; j++)
			{
				if(d[per[j]][i] == 2e9)
				{
					check[i] = true;
					break;
				}
				sum[i] += d[per[j]][i] * d[per[j]][i];
			}
		}

		i64 mn = 9999987654321, index;
		
		for(i32 i = 1; i <= p; i++)
		{
			if(check[i])continue;

			if(sum[i] < mn)
			{
				index = i;
				mn = sum[i];
			}
		}
		cout<<index<<" "<<mn<<"\n";
	}
	return 0;
}
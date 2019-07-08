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
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 n, m, k;
i32 a[109][109], b[109][109];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(i32 i = 0; i < n; i++)
		for(i32 j = 0; j < m; j++)
			cin>>a[i][j];
	cin>>m>>k;
	for(i32 i = 0; i < m; i++)
		for(i32 j = 0; j < k; j++)
			cin>>b[i][j];

	for(i32 i = 0; i < n; i++){
		for(i32 j = 0; j < k; j++)
		{
			i32 temp = 0;
			for(i32 l = 0; l < m; l++)temp+=a[i][l]*b[l][j];
			cout<<temp<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
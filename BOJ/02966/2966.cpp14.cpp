#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 n, cnt[3];
char data[109], a[3] = {'A', 'B', 'C'}, b[4] = {'B', 'A', 'B', 'C'}, g[6] = {'C', 'C', 'A', 'A', 'B', 'B'};
char name[3][10] = {"Adrian", "Bruno", "Goran"};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>data;
	for(i32 i = 0; i<n; i++)
	{
		if(data[i]==a[i%3])cnt[0]++;
		if(data[i]==b[i%4])cnt[1]++;
		if(data[i]==g[i%6])cnt[2]++;
	}
	i32 mx = -1;
	for(i32 i = 0; i<3; i++)if(mx<cnt[i])mx=cnt[i];
	cout<<mx<<"\n";
	for(i32 i = 0; i<3; i++)if(mx==cnt[i])cout<<name[i]<<"\n";
	
	return 0;
}
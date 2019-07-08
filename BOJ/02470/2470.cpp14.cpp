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
i32 n;
i64 data[100009];
i32 ansl, ansr, mn = 2e9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(i32 i = 0; i < n; i++)cin>>data[i];
	sort(data, data+n);
	i32 left = 0, right = n-1;

	while(left<right)
	{
		i64 val = data[left]+data[right];
		if((i64)fabs(val)<mn)
		{
			ansl = data[left];
			ansr = data[right];
			mn = (i64)fabs(val); 
		}
		if(val<0)left++;
		else if(val==0)break;
		else right--;
	}
	cout<<ansl<<" "<<ansr;
	return 0;
}
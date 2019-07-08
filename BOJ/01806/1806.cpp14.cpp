#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i64 n, s, data[100009], mn = 2e9;bool flag=false;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>s;
	for(int i = 0; i<n; i++)cin>>data[i];
	i64 left = 0, right = 0;
	i64 sum=data[0];
	while(left<n&&right<n)
	{
		//cout<<sum<<"\n";
		if(sum>=s)
		{
			//cout<<left<<" "<<right<<"\n";
			flag=true;
			mn = min(mn, right-left);
			sum -= data[left];
			left++;
		}
		else
		{
			if(right<n-1)
			{right++;
			sum += data[right];}
			else right++;
		}
	}
	cout<<(flag?mn+1:0);
	return 0;
}
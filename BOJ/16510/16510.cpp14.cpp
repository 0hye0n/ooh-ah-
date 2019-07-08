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

i64 n, m, prefix[200009];

i64 search(i64 sum)
{
	i32 left = 0, mid, right = n-1;
	
	while(left<=right)
	{
		mid = (left + right)/2;	

		if(prefix[mid]<sum)
		{
			left = mid+1;
		}
		else if(prefix[mid]==sum)
		{
			return mid;
		}
		else
		{
			right = mid-1;
		}
	}
	return right;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	i64 tsum = 0;
	for(register int i = 0; i < n; i++)
	{
		i64 temp;cin>>temp;
		tsum += temp;
		prefix[i] = tsum;
	}
	while(m--)
	{
		i64 t;cin>>t;
		cout<<search(t)+1<<"\n";
	}

	return 0;
}
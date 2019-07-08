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

i32 n, data[1009], temp[1000009], mx = -1;

bool search(i64 find)
{
	i32 left = 0, right = n-1, mid;
	bool flag = false;

	while(left<=right)
	{
		mid = (left+right)/2;
		if(find<data[mid]) right = mid - 1;
		else if(find==data[mid]){flag = true;break;}
		else left = mid + 1;
	}
	return flag;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(i32 i = 0; i < n; i++)cin>>data[i];
	sort(data, data+n);
	i32 pos = 0;
	for(i32 i = 0; i < n; i++)
		for(i32 j = i; j < n; j++)
		{
			temp[pos] = data[i]+data[j];
			pos++;
		}
	sort(temp, temp+pos);

	for(i32 i = n-1; i >= 0; i--)
	{
		for(i32 j = 0; j < pos && temp[j] <= data[i]; j++)
		{
			if(search(data[i]-temp[j]))
			{
				mx = max(data[i], mx);
			}
		}
	}
	cout<<mx;
	
	return 0;
}
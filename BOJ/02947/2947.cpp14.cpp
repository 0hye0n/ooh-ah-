#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
void swap(i32 *x, i32 *y)
{
	i32 temp = *x;
	*x = *y;
	*y = temp;
}

i32 data[5];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(i32 i = 0; i<5; i++)cin>>data[i];

	for(i32 i = 0; i<5; i++)
	{
		for(i32 j = 1; j<5; j++)
		{
			if(data[j]<data[j-1])
			{
				swap(&data[j], &data[j-1]);
				cout<<data[0]<<" "<<data[1]<<" "<<data[2]<<" "<<data[3]<<" "<<data[4]<<"\n";
			}
		}
	}
	return 0;
}
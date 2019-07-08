#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 n;
vector <i32> data;
bool flag = false;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	while(1)
	{
		for(i32 i = 2;;i++)
		{
			if(i>n){flag=true;break;}
			if(n%i==0)
			{
				data.push_back(i);
				n/=i;
				break;
			}
		}
		if(flag){if(n!=1)data.push_back(n);break;}
	}
	sort(data.begin(), data.end());
	i32 size = data.size();
	for(i32 i = 0; i<size; i++)cout<<data[i]<<"\n";
	return 0;
}
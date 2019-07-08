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

i64 a, b;

i64 GCD(i64 x, i64 y)
{
	i64 a = max(x, y);
	i64 b = min(x, y);
	i64 R = a % b;

	while(R)
	{
		a = b;
		b = R;
		R = a % b;
	}
	return b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>b;
	i64 size = GCD(a, b);
	for(i64 i = 0; i < size; i++)cout<<"1";
	return 0;
}
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 a, b;
char op;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(1)
	{
		cin>>a;
		if(op==0){cin>>op;b=a;continue;}
		else if(op=='=')
		{
			cout<<b;
			break;
		}
		else
		{
			switch(op)
			{
				case '+':
				b+=a;
				break;
				case '-':
				b-=a;
				break;
				case '*':
				b*=a;
				break;
				case '/':
				b/=a;
			}
		}
		cin>>op;
	}
	return 0;
}
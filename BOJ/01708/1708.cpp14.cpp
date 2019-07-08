#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
struct A{
	i32 x, y;
	i32 p, q;
	A(i32 x1 = 0, i32 y1 = 0) : x(x1), y(y1), p(1), q(0){}
};
bool cmp(const A &a, const A &b)
{
	if(1LL * a.q * b.p != 1LL * a.p * b.q)
		return 1LL * a.q * b.p < 1LL * a.p * b.q;

	if(a.y != b.y)
		return a.y < b.y;

	return a.x < b.x;
}
i64 ccw(const A &a, const A &b, const A &c)
{
	return 1LL * (a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y);
}
i32 n;
A p[100002];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(i32 i = 0; i<n; i++)
	{
		i32 x, y;cin>>x>>y;
		p[i] = A(x, y);
	}
	sort(p, p+n, cmp);
	for(i32 i = 0; i<n; i++)
	{
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	sort(p + 1, p + n, cmp);
	stack<i32> s;
	s.push(0);
	s.push(1);
	i32 next = 2;
	while(next < n)
	{
		while(s.size() >= 2)
		{
			i32 first, second;
			second = s.top();
			s.pop();
			first = s.top();

			if(ccw(p[first], p[second], p[next]) > 0)
			{
				s.push(second);
				break;
			}
		}
		s.push(next++);
	}
	cout<<s.size();
	return 0;
}
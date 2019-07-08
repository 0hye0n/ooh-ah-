#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

//x좌표 기준으로 오름차순 정렬
struct Point
{
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
	bool operator < (const Point &v) const{
		if(y == v.y) return x < v.x;
		else return y < v.y;
	}
};

bool cmpx(const Point &a, const Point &b)
{
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

bool cmpy(const Point &a, const Point &b)
{
	if(a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}

inline int dist(const Point a, const Point b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);  
}

int n, mn;
vector <Point> point;
set <Point> res;
//Point ansxy[2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	
	for(int i = 0; i < n; i++)
	{
		int a, b;cin>>a>>b;
		point.push_back({a, b});
	}

	sort(point.begin(), point.end(), cmpx);
	res = {point[0], point[1]};
	mn = dist(point[0], point[1]);
	int start = 0;
	for(int i = 2; i < n; i++)
	{
		Point now = point[i];
		while(start < i)
		{
			auto p = point[start];
			int x  = now.x - p.x;
			
			if(x * x > mn)
			{
				res.erase(p);
				start++;
			}
			
			else
			{
				break;
			}
		}

		int d = (int)sqrt((double)mn) + 1;
		auto lower_point = Point(-100000, now.y - d);
		auto upper_point = Point(100000, now.y + d);
		auto lower = res.lower_bound(lower_point);
		auto upper = res.upper_bound(upper_point);
		for(auto it = lower; it != upper; it++)
		{
			int d = dist(now, *it);
			if(d < mn)
			{
				mn = d;
			}
		} 
		res.insert(now);
	}
	cout<<mn;
	return 0;
}
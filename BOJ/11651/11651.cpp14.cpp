#include <bits/stdc++.h>

using namespace std;

struct A
{
	int x, y;
};

vector<A> a;

bool compare(const A &a, const A &b)
{
	if(a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		a.push_back({x, y});
	}
	
	sort(a.begin(), a.end(), compare);
	
	for(int i = 0; i<n; i++)
		printf("%d %d\n", a[i].x, a[i].y);
		
	return 0;
}
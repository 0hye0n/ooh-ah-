#include <bits/stdc++.h>

using namespace std;
int n;

vector<pair<double, int> > a(100001);

int main() {
	
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++)
	{
		double x, y, z;
		scanf(" %lf %lf %lf", &x, &y, &z);
		a[i].first = (double)sqrt(x*x+y*y)/z;
		a[i].second = i+1; 
	}
	
	sort(a.begin(), a.begin()+n);
	
	for(int j = 0; j<n; j++)
	{
		printf("%d\n", a[j].second);
	}
	
	
	
	return 0;
}
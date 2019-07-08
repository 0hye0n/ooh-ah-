#include <bits/stdc++.h>
using namespace std;
vector <pair<int, int> > a(3);
int main() {
	
	for(int i = 0; i<3; i++)
		scanf("%d %d", &a[i].first, &a[i].second);
	sort(a.begin(), a.end());
	double k = (double)(a[0].first-a[1].first)/(a[0].second-a[1].second);
	double l = (double)(a[0].first-a[2].first)/(a[0].second-a[2].second);
	double r = (double)(a[1].first-a[2].first)/(a[1].second-a[2].second);
	if((k==l)&&(l==r)&&(k==r)) printf("WHERE IS MY CHICKEN?"); 
	else printf("WINNER WINNER CHICKEN DINNER!");
	return 0;
}

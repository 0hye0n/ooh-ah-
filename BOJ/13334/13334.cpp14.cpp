#include <bits/stdc++.h>

using namespace std;
int x[100000], y[100000], cnt=0, temp, mx=0, n, len;
pair<int, int> p[200000];

int main() {
	scanf("%d", &n);
	for(int i = 0; i<n; i++)scanf(" %d %d", x+i, y+i);
	scanf(" %d", &len);
	for(int i = 0; i<n; i++)
	{
		if(x[i]>y[i])swap(x[i], y[i]);
		if(y[i]-x[i]>len) continue;
		p[cnt++] = {y[i]-len, -1};
		p[cnt++] = {x[i], 1};
	}
	sort(p, p+cnt);
	for(int i = 0; i<cnt; i++)
	{
		temp -= p[i].second;
		if(mx<temp) mx=temp;
	}
	
	printf("%d", mx);
	return 0;
}
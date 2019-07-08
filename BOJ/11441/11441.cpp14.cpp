#include <bits/stdc++.h>

using namespace std;
int data[100001];
int datasum[100001];
int result[100001] = {0};
int main() {
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
	{
		scanf(" %d", &data[i]);
		if(i==0)datasum[i] = data[i];
		else datasum[i] = datasum[i-1]+data[i];
	}
	scanf("%d", &m);
	for(int i = 0; i<m; i++)
	{
		int tmp1, tmp2;
		scanf(" %d %d", &tmp1, &tmp2);
		if(tmp1)result[i] = datasum[tmp2-1]-datasum[tmp1-2];
		else result[i] = datasum[tmp1];
		
	}
		
	for(int i = 0; i<m; i++)
		printf("%d\n", result[i]);
		
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int t[101][51];
int cnt[101];
int ans[101] = {0};

int main() {

	int casenum;
	
	scanf("%d", &casenum);
	
	for(int i = 0; i<casenum; i++)
	{
		scanf("%d", &cnt[i]);
		for(int j = 0; j<cnt[i]; j++)
			scanf("%d", &t[i][j]);
	}
	
	for(int i = 0; i<casenum; i++)
	{
		printf("Case #%d: ", i+1);
		for(int j = 1; j<cnt[i]; j++)
			if(t[i][j]<=t[i][j-1])
				ans[i]++;
		
		printf("%d\n", ans[i]);
	}
	
	

	return 0;
}
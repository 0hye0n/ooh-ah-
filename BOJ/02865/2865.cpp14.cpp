#include <bits/stdc++.h>
 
using namespace std;
int n, m, k;

double score[109];
double sum = 0.0;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j<n; j++)
		{
			int temp;double tempsc;
			scanf(" %d", &temp);
			scanf(" %lf", &tempsc);
			if(score[temp-1]<tempsc) score[temp-1] = tempsc;
		}	
	}
	
	
	
	sort(score, score+n);
	
	for(int i = n-1; i>=n-k; i--)
	{
		sum += score[i];
	}
	
 	printf("%.1lf", sum);
	return 0;
}
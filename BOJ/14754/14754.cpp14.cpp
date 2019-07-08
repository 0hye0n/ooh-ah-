#include<bits/stdc++.h>

using namespace std;
int n, m;
long long sum = 0;
long long tsum = 0;
int data[1009][1009];
int maxn[1009], maxm[1009];
int result;
int main(){
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
		{
			scanf(" %d", &data[i][j]);
			sum+=data[i][j];
		}
		
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
			if(maxn[i]<data[i][j]) maxn[i] = data[i][j];
	
	
	for(int i = 0; i<m; i++)
		for(int j = 0; j<n; j++)
			if(maxm[i]<data[j][i]) maxm[i] = data[j][i];
			
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
			if(maxn[i]==maxm[j]) {
			maxn[i]=0;
			break;
			}
			
	for(int i = 0; i<n; i++)
		tsum += maxn[i];

	for(int i = 0; i<m; i++)
		tsum += maxm[i];
	
	printf("%lld", sum-tsum);

    return 0;
}
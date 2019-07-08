#include <bits/stdc++.h>
using namespace std;
int c;
double data[1009];
int main() {
	scanf("%d", &c);
	for(int i = 0; i<c; i++)
	{
		int n, cnt=0;
		double sum = 0.0, avg;
		scanf(" %d", &n);
		for(int j = 0; j<n; j++)
		{
			scanf(" %lf", &data[j]);
			sum +=data[j];
		}
		avg = sum/(double)n;
		for(int j = 0; j<n; j++)
			if(avg<data[j])cnt++;
		printf("%.3lf%\n", ((double)cnt/n)*100);
	}
	return 0;
}
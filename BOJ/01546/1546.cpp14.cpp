#include <bits/stdc++.h>
using namespace std;
int score[1001];
double sum = 0;
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
		scanf(" %d", &score[i]);
		
	sort(score, score+n);
	for(int i = 0; i<n; i++){
		sum += ((double)score[i]/score[n-1])*100.0;
	}
		
	printf("%.2lf", (double)sum/n);
	return 0;
}

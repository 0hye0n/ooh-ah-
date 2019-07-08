#include <bits/stdc++.h>

using namespace std;

int correct[101];

int main() {
	
	int n, result = 0, score = 0;
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++)
		scanf("%d", &correct[i]);
		
	for(int i = 0; i<n; i++)
		{
			if(correct[i]==0)
				score = 0;
			
			else
				score++;
			
			result += score;
		}
		
	printf("%d", result);
	
		
	return 0;
}
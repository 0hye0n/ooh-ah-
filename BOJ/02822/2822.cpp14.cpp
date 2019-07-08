#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int score[8], tscore[8], result=0, max, premax;
	
	for(int i = 0; i<8; i++)
		scanf("%d", &score[i]);
	
	for(int i = 0; i<8; i++)
		tscore[i] = score[i];
		
	sort(score, score+8);
	
	for(int i = 3; i<8; i++)
		result += score[i];
		
	printf("%d\n", result);
	
	for(int i = 0; i<8; i++)
	{
		for(int j = 3; j<8; j++)
			if(score[j]==tscore[i]) 
				printf("%d ", i+1);
	}
	return 0;
}
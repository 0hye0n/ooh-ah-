#include <bits/stdc++.h>

using namespace std;
 
int oput[4];
int iput[4];
int people[4];
 
int main() {

	int n;
	
	for(int i = 0; i<4; i++){
	scanf("%d %d", &oput[i], &iput[i]);
	if(i==0)
		people[i] = iput[i];
	
	else
		people[i] = people[i-1]+iput[i]-oput[i];	
	}
	
	int max = people[0];
	for(int i = 1; i<4; i++)
		if(people[i]>max) max = people[i];
		
		
	printf("%d", max);	
	
	return 0;
}
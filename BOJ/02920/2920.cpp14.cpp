#include <bits/stdc++.h>
using namespace std;
int music[10];
int cnt=0;
int main() {
	for(int i = 0; i<8; i++)scanf(" %d", &music[i]);
	
	for(int i = 0; i<7; i++)if(music[i]<music[i+1])cnt++;
	
	if(cnt==0)printf("descending");
	else if(cnt==7)printf("ascending");
	else printf("mixed");
	return 0; 
}
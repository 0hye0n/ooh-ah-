#include <bits/stdc++.h>

using namespace std;
int i = 12, k = 0; char result[4];
int main() {
	while(i--){
		int j;
		scanf("%d", &j);
		if(j==0) k++;
		if((i%4==0)&&i!=12){
			if(k==0) result[i/4] = 'E';
			else result[i/4] = 'A'+k-1;
			k = 0;
		}
	}
	for(int i = 2; i>=0; i--)
		printf("%c\n", result[i]);
	return 0;
}

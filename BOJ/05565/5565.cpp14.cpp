#include <bits/stdc++.h>

using namespace std;


int main() {
	
	int result, sum = 0;
	scanf("%d", &result);
	
	for(int i = 0; i<9; i++){
		int temp;
		scanf("%d", &temp);
		sum += temp;
	}
	
	printf("%d", result-sum);
	return 0;
}
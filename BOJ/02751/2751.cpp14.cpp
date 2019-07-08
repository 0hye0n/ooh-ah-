#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


using namespace std;

int val[1000001];
int temp[1000001];

int main() {
	
	int num;
	
	scanf("%d", &num);
	
	for(int i = 0; i < num; i++)
		scanf(" %d", &val[i]);
	
	sort(val, val+num);
	
		
	for(int i = 0; i < num; i++){
		printf("%d\n", val[i]);
	}
	
	
	
	//system("pause");
	return 0;
}
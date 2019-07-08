#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


using namespace std;

int cnt[10001];

int main() {
	int n;
	
	scanf("%d", &n);
	for(int i = 0 ; i <n; i++)
	{
		int temp;
		scanf("%d", &temp);
		cnt[temp]++;
	}
	
	for(int i = 1; i<=10000; i++)
	{
		for(int j = 0; j<cnt[i] ; j++)
			printf("%d\n", i);
	}
	//system("pause");
	return 0;
}
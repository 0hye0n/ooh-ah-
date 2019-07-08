#include <bits/stdc++.h>
using namespace std;
int result[5];
int main() 
{
	for(int i = 0; i<5; i++)
	{
		int sum = 0;
		for(int j = 0; j<4; j++)
		{
			int temp;scanf(" %d", &temp);
			sum += temp;
		}
		result[i] = sum;
	}
	int max = 0;
	for(int i = 0; i<5; i++)if(result[i]>result[max])max=i;
	printf("%d %d", max+1, result[max]);
	return 0;
}
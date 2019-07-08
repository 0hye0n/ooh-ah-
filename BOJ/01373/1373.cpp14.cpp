#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
char data[1000009];
int result[1000009];
int main() 
{
	scanf("%s", &data);
	int len = strlen(data);
	int i, j;
	for(i = len-1, j = 0; i>=0; i-=3, j++)
	{
		int temp = 2, num = data[i]-48;
		for(int k = i-1; k>i-3&&k>=0; k--)
		{
			num += (data[k]-48)*temp;
			temp*=2;
		}
		result[j] = num;
	}
	
	for(int i = j-1; i>=0; i--)
		printf("%d", result[i]);
	
	return 0;
}
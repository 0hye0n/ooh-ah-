#include <bits/stdc++.h>
using namespace std;
int n, cnt=0;
int coin[6] = {500, 100, 50, 10, 5, 1};
int main() 
{
	scanf(" %d", &n);
	n = 1000-n;
	for(int i = 0; i<6; i++)
	{
		cnt += n/coin[i];
		n %=coin[i];
	}
	printf("%d", cnt);
	return 0;
}
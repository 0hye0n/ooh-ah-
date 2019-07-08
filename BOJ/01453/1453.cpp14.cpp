#include <bits/stdc++.h>
using namespace std;
bool check[101];int cnt=0;
int main() 
{
	int n; scanf("%d", &n);
	for(int i = 0; i<n; i++)
	{
		int temp;scanf(" %d", &temp);
		if(!check[temp])check[temp]=true;
		else cnt++;
	}
	printf("%d", cnt);

	return 0;
}
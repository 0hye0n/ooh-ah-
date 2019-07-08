#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[2];
int main() 
{
	scanf(" %d", &n);
	for(int i = 0; i<n; i++)
	{
		int temp;scanf(" %d", &temp);
		cnt[temp]++;
	}
	if(cnt[0]<cnt[1])printf("Junhee is cute!");
	else printf("Junhee is not cute!");
	return 0;
}
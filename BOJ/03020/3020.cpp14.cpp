#include <bits/stdc++.h>
 
using namespace std;
int n, h, cnt = 0, mn = 200009;
int obstacle1[500009];
int obstacle2[500009];
int up;
int down;

int main() {
	scanf("%d %d", &n, &h);
	
	for(int i = 0; i<n ;i++)
	{
		int temp;
		scanf("%d", &temp);
		if(i%2==0)
			obstacle1[temp]++;
		else
			obstacle2[temp]++;
	}
	up = 0;down = n/2;
	
	for(int i = 0; i<h; i++)
	{
		up += obstacle2[h-i];
		down -= obstacle1[i];
		
		if(mn>(up+down))
		{
			mn = up+down;
			cnt = 1;
		}
		else if(mn == (up+down))
			cnt++;

	}
	
	printf("%d %d\n", mn, cnt);
	return 0;
}
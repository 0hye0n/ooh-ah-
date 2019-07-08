#include <bits/stdc++.h>
using namespace std;
int s, t;
int main()
{
	for(int i = 0; i<4; i++)
	{
		int temp;scanf(" %d", &temp);
		s+=temp;
	}
	for(int i = 0; i<4; i++)
	{
		int temp;scanf(" %d", &temp);
		t+=temp;
	}
	printf("%d", s>t?s:t);
	return 0;
}

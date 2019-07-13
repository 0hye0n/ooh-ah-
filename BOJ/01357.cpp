#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

char x[5], y[5];
int xsize, ysize, res[5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>x>>y;
	xsize = strlen(x);
	ysize = strlen(y);

	for(int i = 0; i < xsize; i++)
	{
		res[i] = x[i] - '0';
	}
	for(int i = 0; i < ysize; i++)
	{
		res[i] += y[i] - '0';
	}

	for(int i = 0; i < 4; i ++)if(res[i]>= 10){res[i + 1] += res[i] / 10; res[i] %= 10;}

	int size;bool flag = false;
	for(int i = 4; i >= 0; i--)if(res[i] != 0){size = i + 1;break;}
	for(int i = 0; i < size; i++)
	{
		if(res[i] != 0)
		{
			flag = true;	
		}
		if(flag)cout<<res[i];
			
	}
	return 0;
}
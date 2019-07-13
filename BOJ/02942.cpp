#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int r, g;
vector <int> rd, gd;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>r>>g;
	for(long long i = 1; i * i <= r; i++)
	{
		if(r % i == 0)
		{
			if(r / i == i)rd.push_back(i);

			else
			{
				rd.push_back(i);
				rd.push_back(r / i);
			} 
		}
	}

	for(long long i = 1; i * i <= g; i++)
	{
		if(g % i == 0)
		{
			if(g / i == i)gd.push_back(i);

			else
			{
				gd.push_back(i);
				gd.push_back(g / i);
			} 
		}
	}
	sort(rd.begin(), rd.end());
	sort(gd.begin(), gd.end());

	int rpos = 0, gpos = 0, rsize = rd.size(), gsize = gd.size();

	while(rpos < rsize && gpos < gsize)
	{
		if(rd[rpos] == gd[gpos])
		{
			cout<<rd[rpos]<<" "<<r / rd[rpos]<<" "<<g / rd[rpos]<<"\n";
			rpos++;
			gpos++;
		}
		else if(rd[rpos] > gd[gpos])gpos++;
		else rpos++;
	}

	return 0;
}
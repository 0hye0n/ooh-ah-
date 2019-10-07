#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

string data, res;
int cnt[10] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>data;
	int len = data.length(), pos = 0;

	while(pos < len)
	{
		bool flag = false;

		for(int i = data[pos] - '0'; i >= 0; i++)
		{
			if(cnt[i] > 0)
			{
				flag = true;
				

			}
		}
	}
	return 0;
}
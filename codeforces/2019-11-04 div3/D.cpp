#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin>>q;
	while(q--)
	{
		long long n, k;cin>>n>>k;
		string data;cin>>data;
		int one_pos = -1, zero_pos = -1;

		for(int i = 0; i < n; i++)if(data[i] == '1'){one_pos = i;zero_pos = i;break;}
		for(int i = zero_pos; i < n; i++)if(data[i]=='0'){zero_pos = i;break;}



		if(one_pos == -1 || one_pos == zero_pos)
		{
			cout<<data<<"\n";
			continue;
		}

		while(1)
		{
			//cout<<one_pos<<" "<<zero_pos<<"\n";
			if(zero_pos - one_pos < k)swap(data[one_pos], data[zero_pos]);
			else
			{
				if(k > 0)
				swap(data[zero_pos], data[zero_pos - k]);
				break;
			}
			k -= zero_pos - one_pos;
			one_pos++;
			bool found = false;
			for(int i = zero_pos; i < n; i++)
			{
				if(data[i] == '0')
				{
					found = true;
					zero_pos = i;
					break;
				}
			}

			if(!found)break;
		}

		cout<<data<<"\n";
	}


	return 0;
}
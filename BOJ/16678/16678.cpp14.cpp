#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int n, mx = -1;
lld data[100009];
lld hack = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i<n; i++)cin>>data[i];
	sort(data, data+n);
	lld pos = 0;
	for(int i = 1; pos<n; pos++)
	{
			if(pos<n-1&&data[pos]!=data[pos+1])
			{
				hack += data[pos]-i;
				i++;	
			}
			else if(data[pos]>i)
			{
				hack += data[pos]-i;
				i++;
			}
			

	}

	cout<<hack;

	return 0;
}

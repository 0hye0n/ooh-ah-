#include <bits/stdc++.h>

using namespace std;

int q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin>>q;
	while(q--)
	{
		long long a, b, n, s;
		cin>>a>>b>>n>>s;

		long long total = a * n;

		if(total > s)
		{
			total = (s / n) * n; 
		}

		if(s - total <= b) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}
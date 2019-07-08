#include <bits/stdc++.h>

using namespace std;

bool check[1000009];
long long m, n;
vector <int> prime;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;

	for(long long i = 2; i <= n; i++)
		for(long long j = 2; i * j <= n; j++)
			check[i * j] = true;
	for(int i = 2; i <= n; i++)if(!check[i])prime.push_back(i);


	int size = prime.size();
	for(int i = 0; i < size; i++)
	{
		if(prime[i] >= m)cout<<prime[i]<<"\n";
	}
	return 0;
}
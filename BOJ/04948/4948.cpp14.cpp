#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

vector <long long> prime;
bool check[300009];
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(register long long i = 2; i <= 300000L; i++)
		for(register long long j = 2; i * j <= 300000L; j++)
			check[i * j] = true;
	for(int i = 2; i <= 300000; i++)if(!check[i])prime.push_back(i);

	int size = prime.size();
	cin>>n;
	while(n)
	{
		int mx = 2 * n, cnt = 0;
		for(int i = 0; i < size && prime[i] <= mx; i++)
		{
			if(prime[i] > n)cnt++;
		}
		cout << cnt << "\n";
		cin>>n;
	}
	return 0;
}
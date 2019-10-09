#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 15746

using namespace std;

int n, arr[1000009];

long long solve(int target)
{
	if(target == 0) return 0;
	if(target == 1) return 1;
	if(target == 2) return 2;

	if(arr[target] != -1) return arr[target];
	long long ret = (solve(target - 1) % MOD + solve(target - 2) % MOD) % MOD;
	arr[target] = ret;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill(arr, arr + 1000009, -1);
	cin>>n;
	cout<<solve(n);		
	return 0;
}
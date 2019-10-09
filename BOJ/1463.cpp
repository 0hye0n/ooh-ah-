#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, arr[1000009];

int solve(int n)
{
	if(n == 1)return 0;

	if(arr[n] != -1) return arr[n];

	int res = solve(n - 1) + 1;
	if(n % 2 == 0) res = min<int>(res, solve(n / 2) + 1);
	if(n % 3 == 0) res = min<int>(res, solve(n / 3) + 1);
	
	arr[n] = res;

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill(arr, arr + 1000001, -1);
	cin>>n;
	cout<<solve(n);
	return 0;
}
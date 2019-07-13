#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, c, arr[109], cnt = 0;
bool check[2000009];
vector <int> v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>c;
	for(int i = 0; i < n; i++)cin>>arr[i];
	sort(arr, arr + n);
	v.push_back(arr[0]);
	for(int i = 1; i < n; i++)if(arr[i] != arr[i - 1])v.push_back(arr[i]);
	int size = v.size();
	for(int i = 0; i < size; i++){
		for(int j = v[i]; j <= c; j += v[i])check[j] = true;
	}

	for(int i = 0; i <= c; i++)if(check[i])cnt++;
	cout<<cnt;
	return 0;
}
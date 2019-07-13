#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> data;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(int i = 0; i < n; i++)data.push_back(i + 1);
	int cur = 0;
	cout<<"<";

	for(int i = 0; i < n - 1; i++)
	{
		cur += k-1;
		cur %= n - i;

		cout<<data[cur]<<", ";
		data.erase(data.begin() + cur);
	}
	cout<<data[0]<<">";

	return 0;
}
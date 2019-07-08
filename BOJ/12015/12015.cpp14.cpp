#define USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
vector <int> ans;
int n, data[1000009], cnt=0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;

	for(int i = 0; i < n; i++)cin>>data[i];
	
	ans.push_back(-2e9);
	for (int i = 0; i < n; i++) {
	    if (ans.back() < data[i]) {
	        ans.push_back(data[i]);
	           cnt++;
	    }
	    else {
	        auto it = lower_bound(ans.begin(), ans.end(), data[i]);
	        *it = data[i];
	    }
	}
	cout<<cnt;
	return 0;
}
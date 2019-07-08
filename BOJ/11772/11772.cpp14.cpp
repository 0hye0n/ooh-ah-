#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n;
lld sum = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	while(n--){
		lld temp;cin>>temp;
		lld expon = temp%10;
		temp = temp/10;
		sum += (lld)pow(temp, expon);
	}
	cout<<sum;
	return 0;
}
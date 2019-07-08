#include <bits/stdc++.h>

using namespace std;
int a[1000002];
int b[1000002];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i = 0; i<t; i++)
		cin>>a[i]>>b[i];
	for(int i = 0; i<t; i++)
		cout<<a[i]+b[i]<<"\n";
	return 0;
}
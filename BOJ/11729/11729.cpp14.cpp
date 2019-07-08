#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n;
void solve(int n, int s, int m, int e){
	//cout<<n<<" "<<s<<" "<<m<<" "<<e<<"\n";
	if(n==1)
	{
		cout<<s<<" "<<e<<"\n";
		return;	
	}

	solve(n-1, s, e, m);
	cout<<s<<" "<<e<<"\n";
	solve(n-1, m, s, e);
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	lld data = pow(2, n)-1; 
	cout<<data<<"\n";
	solve(n, 1, 2, 3);
	return 0;
}
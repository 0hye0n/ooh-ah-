#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n;
int result[1009];
inline void solve(){
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i<n; i++){
		int t[3];cin>>t[0]>>t[1]>>t[2];
		
		if(t[0]==t[1]&&t[1]==t[2])result[i] = 10000+t[0]*1000;
		else if(t[0]==t[1]||t[1]==t[2]) result[i] = 1000+t[1]*100;
		else if(t[0]==t[2]) result[i] = 1000+t[0]*100;
		else
		{
			sort(t, t+3);
			result[i] = t[2]*100;
		}
	}
	sort(result, result+n);
	cout<<result[n-1];
	return 0;
}
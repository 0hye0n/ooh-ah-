#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
lld n, m, l, r;
lld A[10009];
lld sum = 0, cnt=0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	l=0;r=0;
	cin>>n>>m;
	for(int i = 0;i<n; i++) cin>>A[i];
	sum = A[0];
	while(l<n&&r<n)
	{
		if(sum<m){
			r++;
			sum += A[r];}
			
		else if(sum==m){
			sum -= A[l];
			l++;cnt++;}
		
		else{
			sum -= A[l];
			l++;}	
	}
	cout<<cnt;
	return 0;
}
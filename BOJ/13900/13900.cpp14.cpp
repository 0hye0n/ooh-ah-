#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n, data[100009];
lld sum = 0, temp = 0;

int main() 
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i = 0; i<n; i++)cin>>data[i];
	for(int i = n-2; i>=0; i--)
	{
			temp +=data[i+1];
			sum += data[i]*temp;
	}
	cout<<sum<<"\n";
	return 0;
}
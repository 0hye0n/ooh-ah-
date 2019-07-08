#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
bool check[10009];
int n;
int d1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int d3[] = {7, 4, 1, 8, 5, 2, 9, 6, 3};
int d7[] = {3, 6, 9, 2, 5, 8, 1, 4, 7};
int d9[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin>>n){
	lld cnt=0;int cal=n;
	while(1)
	{
		while(cal%10==1){cal/=10;cnt++;}
		if(cal==0)break;
		int temp = cal%10;
		int diff = (11-temp)%10;
		switch(n%10)
		{
			case 1:
			cal = cal+n*d1[diff-1];
			break;

			case 3:
			cal = cal+n*d3[diff-1];
			break;

			case 7:
			cal = cal+n*d7[diff-1];
			break;

			case 9:
			cal = cal+n*d9[diff-1];
			break;
		}
	}
	cout<<cnt<<"\n";
	}

	return 0;
}

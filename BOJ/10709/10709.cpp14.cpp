#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int h, w;
char d[109][109];
int res[109][109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>h>>w;
	for(int i = 0; i<h; i++)
	{
		int temp = -1;bool check = false;
		for(int j = 0; j<w; j++){
			cin>>d[i][j];
			if(d[i][j]=='c'){check = true;temp=0;}
			res[i][j]=temp;
			if(check)temp++;
		}
	}

	for(int i = 0; i<h; i++){
		for(int j = 0; j<w; j++)
			cout<<res[i][j]<<" ";
		cout<<"\n";
	}

	return 0;
}
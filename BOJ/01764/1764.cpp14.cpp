#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n, m, cnt=0;
char temp[20];
set <string> data;
vector <string> result;
int main() 
{	
	scanf("%d %d", &n, &m);
	for(int i = 0; i<n; i++)
	{
		cin>>temp;
		data.insert(temp);	
	}
	
	for(int i = 0; i<m; i++)
	{
		cin>>temp;
		if(data.count(temp)!=0)
		{
			cnt++;
			result.push_back(temp);
		}
	}
	sort(result.begin(), result.end());
	cout<<cnt<<"\n";
	for(int i = 0; i<result.size(); i++)cout<<result[i]<<"\n";
	return 0;
}
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 n, i=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	n++;
	while(n--)
	{

		string data;
		getline(cin, data);
		if(i==0){i++;continue;}
		i32 len = data.length(), cntb=0, cntg=0;
		for(i32 i = 0; i<len; i++)
		{
			if(data[i]=='G'||data[i]=='g')cntg++;
			if(data[i]=='B'||data[i]=='b')cntb++;
		}
		if(cntg>cntb)cout<<data<<" is GOOD\n";
		else if(cntg==cntb)cout<<data<<" is NEUTRAL\n";
		else cout<<data<<" is A BADDY\n";
	}
	return 0;
}
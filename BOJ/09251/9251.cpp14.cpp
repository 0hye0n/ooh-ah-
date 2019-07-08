#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;

string s1, s2;

i32 lcs[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string temp1, temp2;
	cin>>temp1>>temp2;
	s1 = '0' + temp1;
	s2 = '0' + temp2;

	i32 len1 = s1.size();
	i32 len2 = s2.size();

	for(i32 i = 0; i<len1; i++)
	{
		 for(i32 j = 0; j<len2; j++)
		 {
		 	if(i==0 || j==0)
		 	{
		 		lcs[i][j] = 0;
		 		continue;
		 	}

		 	if(s1[i]==s2[j])
		 		lcs[i][j] = lcs[i-1][j-1] +1;

		 	else
		 	{
		 		if(lcs[i-1][j] > lcs[i][j-1])
		 			lcs[i][j] = lcs[i-1][j];
		 		else
		 			lcs[i][j] = lcs[i][j-1];
		 	}

		 }
	}
	cout<<lcs[len1-1][len2-1]<<"\n";


	return 0;
}
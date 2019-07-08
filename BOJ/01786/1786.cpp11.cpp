#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;

vector<i32> getPI(char *p)
{
	i32 m = strlen(p), j=0;
	vector<i32> pi(m, 0);
	for(i32 i = 1; i<m; i++)
	{
		while(j > 0 && p[i] != p[j]) j = pi[j-1];
		if(p[i]==p[j])pi[i] = ++j;
	}
	return pi;
}

vector<i32> kmp(char *s, char *p)
{
	vector<i32> ans;
	auto pi = getPI(p);
	i32 n = strlen(s), m = strlen(p), j = 0;
	for(i32 i = 0; i<n; i++)
	{
		while(j>0 && s[i] != p[j]) j = pi[j-1];
		if(s[i]==p[j])
		{
			if(j==m-1)
			{
				ans.push_back(i-m+1);
				j = pi[j];
			}
			else
			{
				j++;
			}
		}
	} 
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	char s[1000009], p[1000009];
	gets(s);
	gets(p);
	auto matched = kmp(s, p);
	cout<<(i32)matched.size()<<"\n";
	for(auto i : matched) cout<<i+1<<" ";
	
	return 0;
}
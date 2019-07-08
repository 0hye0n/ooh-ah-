#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
char data[209];i32 size, check[26];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	gets(data);size = strlen(data);
	while(size!=1||data[0]!='*')
	{
		bool flag = false;
		for(i32 i = 0; i<size; i++)
		{
			if(data[i]==' ')continue;
			check[data[i]-'a']=true;
		}
		for(i32 i = 0; i<26; i++)
		{
			if(!check[i]){flag=true;break;}
		}
		cout<<(flag?'N':'Y');cout<<"\n";
		memset(check, false, sizeof(check));
		memset(data, 0, sizeof(data));
		gets(data);size = strlen(data);
	}
	return 0;
}
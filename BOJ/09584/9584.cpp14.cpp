#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define push_back pb
#define emplace_back eb
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef short i8;
typedef int i32;
typedef long long i64;
typedef unsigned short ui8;
typedef unsigned int ui32;
typedef unsigned long long ui64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
string data;
i32 n, cnt=0, tot=0;
queue <string> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>data>>n;
	for(i32 i = 0; i < 9; i++)
	{
		if(data[i]=='*')continue;
		tot++;
	}

	for(i32 i = 0; i < n; i++)
	{
		i32 num=0;string temp;cin>>temp;
		for(i32 j = 0; j < 9; j++)
		{
			if(temp[j]=='*')continue;
			else if(data[j]==temp[j])num++;
		}
		if(num==tot)
		{
			cnt++;
			ans.push(temp);
		}
	}
	cout<<cnt<<"\n";
	while(!ans.empty())
	{
		cout<<ans.front()<<"\n";
		ans.pop();
	}

	return 0;
}
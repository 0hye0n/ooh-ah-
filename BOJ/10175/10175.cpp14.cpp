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

i32 n, cnt[4];
char ans[4][20] = {"Bobcat", "Coyote", "Mountain Lion", "Wolf"};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(i32 i = 0; i < n; i++)
	{
		memset(cnt, 0, sizeof(cnt));
		string name, data;cin>>name>>data;
		bool flag = false;
		i32 size = data.length(), mx=0;
		
		for(i32 j = 0; j < size; j++)
		{
			switch(data[j])
			{
				case 'B':
				cnt[0]+=2;break;
				case 'C':
				cnt[1]+=1;break;
				case 'M':
				cnt[2]+=4;break;
				case 'W':
				cnt[3]+=3;break;
			}
		}
		for(i32 j = 1; j < 4; j++)
		{
			if(cnt[j]>cnt[mx])mx=j;
			else if(cnt[j]==cnt[mx])flag=true;
		}

		if(flag)cout<<name<<": There is no dominant species\n";
		else cout<<name<<": The "<<ans[mx]<<" is the dominant species\n";

	}
	return 0;
}
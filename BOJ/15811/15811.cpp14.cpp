#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define push_back pb
#define emplace_back eb
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;

i64 cnt=0, cntdata[29];
i64 result[3][11], save[11], sum1=0, sum2=0, sum3=0;
char data[3][21];
bool num[10], check[30], correct=false, flag=false;

void solve(i32 pos)
{
	if(pos==cnt)
	{
		for(i32 i = 0; i<cnt; i++)
		{
			sum1 += result[0][i]*save[i];
			sum2 += result[1][i]*save[i];
			sum3 += result[2][i]*save[i];
		}
		if(sum1+sum2==sum3) flag =true;
		sum1=sum2=sum3=0;
		return;
	}
	for(i32 i = 0; i < 10; i++)
	{
		if(num[i])continue;
		save[pos] = i;
		num[i] = true;
		solve(pos+1);
		num[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>data[0]>>data[1]>>data[2];
	for(i32 i = 0; i<3; i++)
	{
		i32 size = strlen(data[i]);
		reverse(data[i], data[i]+size);
	}

	for(i32 i = 0; i < 3; i++)
	{
		i64 cipher = 1;

		for(i32 j = 0; data[i][j]; j++)
		{
			if(!check[data[i][j]-'A']&&cnt<=10)
			{
				check[data[i][j]-'A'] = true;
				cntdata[data[i][j]-'A'] = cnt;
				result[i][cnt] += 1*cipher;
				cnt++;
			}
			else if(check[data[i][j]-'A'])
			{
				i64 temp = cntdata[data[i][j]-'A'];
				result[i][temp] += 1*cipher;
			}
			else {
				correct = true;
				break;
			}
			cipher *= 10;
		}
	}

	if(cnt<=10&&!correct)
	{
		solve(0);
		if(flag)cout<<"YES";
		else cout<<"NO";
	}
	else cout<<"NO";
	
	return 0;
}
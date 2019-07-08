#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
//#define push_back pb
//#define emplace_back eb
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

/*
..#..
.#.#.
#.X.#
.#.#.
..#..
*/

/*
..*..
.*.*.
*.X.*
.*.*.
..*..
*/

i32 pos = 0;
string data;
char ptp[6][6] = {"..#..", ".#.#.", "#.X.#", ".#.#.", "..#.."};
char wendy[6][6] = {"..*..", ".*.*.", "*.X.*", ".*.*.", "..*.."};

char ans[10][200];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>data;
	i32 size = data.length();

	for(i32 i = 1; i <= size; i++)
	{
		if(i%3 == 0)
		{
			for(i32 j = 0; j < 5; j++)
			{
				for(i32 k = pos; k < pos + 5; k++)
				{
					ans[j][k] = wendy[j][k-pos];
				}
			}
			ans[2][pos+2] = data[i-1];
		}

		else
		{
			for(i32 j = 0; j < 5; j++)
			{
				for(i32 k = pos; k < pos + 5; k++)
				{
					ans[j][k] = ptp[j][k-pos];
				}
			}
			ans[2][pos+2] = data[i-1];
		}
		pos += 4;
	}
	
	i32 temp = 0;
	for(i32 i = 0; i < size; i++)
	{
		if(i != 0 && i % 3 == 0)
		{
			ans[2][temp - 2] = '*';
			ans[2][temp + 2] = '*';
		}

		temp += (i==0)?2:4;
	}

	for(i32 i = 0; i < 5; i++){
		for(i32 j = 0; j <=pos; j++)
			cout<<ans[i][j];
		cout<<"\n";
	}

	return 0;
}
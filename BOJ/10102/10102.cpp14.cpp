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

i32 v, cnta=0, cntb=0;
string data;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>v>>data;
	for(i32 i = 0; i < v; i++)
	{
		if(data[i]=='A')cnta++;
		else cntb++;
	}	
	if(cnta>cntb) cout<<"A";
	else if(cnta==cntb) cout<<"Tie";
	else cout<<"B";
	return 0;
}
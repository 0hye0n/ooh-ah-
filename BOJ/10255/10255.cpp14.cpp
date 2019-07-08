#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
bool flag = false;i32 temp = 0;
pii64 rec[4], line[2];
i32 t;

bool judge(pii64 c, pii64 d)
{
	f64 t1 = (double)(c.first-rec[0].first)/(c.second-rec[0].second);
	f64 t2 = (double)(d.first-rec[0].first)/(d.second-rec[0].second);
	f64 t3 = (double)(c.first-rec[1].first)/(c.second-rec[1].second);
	f64 t4 = (double)(d.first-rec[1].first)/(d.second-rec[1].second);
	f64 t5 = (double)(c.first-rec[2].first)/(c.second-rec[2].second);
	f64 t6 = (double)(d.first-rec[2].first)/(d.second-rec[2].second);
	f64 t7 = (double)(c.first-rec[3].first)/(c.second-rec[3].second);
	f64 t8 = (double)(d.first-rec[3].first)/(d.second-rec[3].second);
	if(t1==t2||t3==t4||t5==t6||t7==t8)return true;
	else return false;
}

i32 ccw(pii64 a, pii64 b, pii64 c)
{
	i64 res = a.first*b.second + b.first*c.second + c.first*a.second;
	res -= a.second*b.first + b.second*c.first + c.second*a.first;
	if(res>0) return 1;
	else if(res==0) return 0;
	else return -1;
}

bool intersect(pii64 a, pii64 b, pii64 c, pii64 d)
{ 
	i32 ab = ccw(a, b, c)*ccw(a, b, d);
	i32 cd = ccw(c, d, a)*ccw(c, d, b);
	if(a>b)swap(a, b);
	if(c>d)swap(c, d);
	if(ab==0&&cd==0)
	{
		temp++;
	
		f64 t1 = (double)(a.first-b.first)/(a.second-b.second);
		f64 t2 = (double)(c.first-d.first)/(c.second-d.second);

		if(b>=c&&a<=d)
		{
			if(t1==t2)
			{
				if((b==c&&b<d)||(a==d&&a>c)){}
				else{flag=true;}
			}
		}
		return b>=c&&a<=d;
	}
	if(ab<=0&&cd<=0)
	{
		if(judge(c, d))temp++;
	}
	return ab<=0&&cd<=0;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		i32 cnt=0;
		for(i32 i = 0; i<2; i++)cin>>rec[i].first>>rec[i].second;
		for(i32 i = 0; i<2; i++)cin>>line[i].first>>line[i].second;
		rec[2].first = rec[0].first;rec[2].second = rec[1].second;
		rec[3].first = rec[1].first;rec[3].second = rec[0].second;

		if(intersect(rec[0], rec[2], line[0], line[1]))cnt++;
		if(intersect(rec[0], rec[3], line[0], line[1]))cnt++;
		if(intersect(rec[1], rec[2], line[0], line[1]))cnt++;
		if(intersect(rec[1], rec[3], line[0], line[1]))cnt++;

		if(flag)cout<<"4\n";
		else cout<<cnt-temp/2<<"\n";
		flag = false;temp=0;
	}
	return 0;
}
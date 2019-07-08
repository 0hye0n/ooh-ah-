#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i64 n, ans=0;
bool check[4000009];
vector <i32> prime;
void getprime()
{
	for(i64 i = 2; i<=n; i++)
	{
		for(i64 j = 2; i * j <= n; j++)if(i*j<=n)check[i*j]=true;
	}
	for(i64 i = 2; i<=n; i++)
		if(!check[i])prime.push_back(i);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	getprime();
	i32 left = 0, right = 0, size = prime.size();
	if(size==0){cout<<"0";}
	else{
		i64 total = prime[0];
		while(left<size&&right<size)
		{
			if(total<n)
			{
				right++;
				if(right<size)total+=prime[right];
			}
			else if(total==n)
			{
				ans++;
				right++;
				if(right<size)total+=prime[right];
			}
			else
			{
				total-=prime[left];
				left++;
			}
		}
		while(right<size)
		{
				right++;
				if(right<size)total+=prime[right];
				if(total==n)ans++;
		}
		while(left<size)
		{
				if(left<size)total-=prime[left];
				left++;
				if(total==n)ans++;

		}
		cout<<ans;
	}
	
	
	return 0;
}
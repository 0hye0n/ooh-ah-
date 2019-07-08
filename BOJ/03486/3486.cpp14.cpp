#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 n;
vector<int> ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	while(n--)
	{
		char t1[19], t2[19];
		i32 a[19], b[19];
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		cin>>t1>>t2;
		i32 l1=strlen(t1), l2=strlen(t2);
		for(i32 i = 0; i<l1; i++)a[i] = t1[i]-'0';
		for(i32 i = 0; i<l2; i++)b[i] = t2[i]-'0';
		i32 len = max(l1, l2);
		for(i32 i = 0; i<len; i++)ans.push_back(a[i]+b[i]);
		for(i32 i = 0; i<len-1; i++)
		{
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
		if(ans[len-1]>=10)
		{
			ans.push_back(ans[len-1]/10);
			ans[len-1]%=10;
		}
		while(!ans.empty()&&ans.back()==0)ans.pop_back();
		reverse(ans.begin(), ans.end());
		while(!ans.empty()&&ans.back()==0)ans.pop_back();
		if(!ans.empty())reverse(ans.begin(), ans.end());
		if(ans.empty())cout<<"0";
		else for(i32 i = 0; i<ans.size(); i++)cout<<ans[i];
		cout<<"\n";
		ans.clear();
	}
	return 0;
}
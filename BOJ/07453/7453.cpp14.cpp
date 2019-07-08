#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int A[4009], B[4009], C[4009], D[4009];
vector <int> t1, t2;
int n;lld ans=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i<n; i++)cin>>A[i]>>B[i]>>C[i]>>D[i];
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
		{
			t1.push_back(A[i]+B[j]);
			t2.push_back(C[i]+D[j]);
		}
	sort(t1.begin(), t1.end());
	sort(t2.begin(), t2.end());
	int size = t1.size();
	int left = 0, right = size-1;
	while(left<size&&right>=0)
	{
		int temp = t1[left]+t2[right];
		if(temp>0) right--;
		else if(temp==0)
		{
			int tl = left, tr = right;
			lld cnt1 = 0, cnt2 = 0;
			while(t1[left]==t1[tl]&&left<size){cnt1++;left++;}
			while(t2[right]==t2[tr]&&right>=0){cnt2++;right--;}
			ans+=cnt1*cnt2;
		}
		else left++;
	}
	while(left<size)
	{
		lld temp = t1[left]+t2[right];
		if(temp==0)ans++;
		left++;
	}
	while(right>=0)
	{
		lld temp = t1[left]+t2[right];
		if(temp==0)ans++;
		right--;
	}
	cout<<ans;
	return 0;
}
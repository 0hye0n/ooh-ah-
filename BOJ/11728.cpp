#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr1[1000009], arr2[1000009];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;

	for(int i = 0; i < n; i++)cin>>arr1[i];
	for(int i = 0; i < m; i++)cin>>arr2[i];

	int top1 = 0, top2 = 0;

	while(top1 < n && top2 < m)
	{
		if(arr1[top1] > arr2[top2])
		{
			cout<<arr2[top2]<<" ";
			top2++;
		}
		else
		{
			cout<<arr1[top1]<<" ";
			top1++;
		}
	}

	while(top1 < n)
	{
		cout<<arr1[top1]<<" ";
		top1++;
	}
	while(top2 < m)
	{
		cout<<arr2[top2]<<" ";
		top2++;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int search(int *a, int left, int right, int find)
{
	int mid;
	while(left<=right)
	{
		mid = (left+right)/2;
		if(a[mid]==find)return 1;
		else if(a[mid]>find) right = mid-1;
		else left = mid+1;
	}
	return 0;
}
int t, data[1000009];
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		int n, m;
		scanf(" %d", &n);
		for(int i = 0; i<n; i++)scanf(" %d", &data[i]);
		sort(data, data+n);
		scanf(" %d", &m);
		for(int i = 0; i<m; i++)
		{
			int temp;scanf(" %d", &temp);
			printf("%d\n", search(data, 0, n-1, temp));
		}
	}
	return 0;
}
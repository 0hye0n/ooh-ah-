#include<bits/stdc++.h>

using namespace std;
int n, m;
int a[100009];
int data[100009];
int check[100009];
int main(){
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
		scanf("%d", &a[i]);
	sort(a, a+n);
	scanf("%d", &m);
	for(int i = 0; i<m; i++)
		scanf("%d", &data[i]);

	for(int i = 0; i<m; i++)
	{
		int mid, left = 0, right = n-1;
		while(left<=right)
		{
			mid = (left+right)/2;
			if(a[mid]==data[i])
			{
				check[i]=1;
				break;
			}
			else if(a[mid]<data[i])
				left = mid+1;
			else if(a[mid]>data[i])
				right = mid-1;
		}
		printf("%d\n", check[i]);
	}
    return 0;
}
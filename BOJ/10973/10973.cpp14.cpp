#include <bits/stdc++.h>

using namespace std;

int n;

int cnt1=-1;
int iput[10009];
int result[10009];

bool desc(int a, int b)
{
	return a > b;
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	int temp = 0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf(" %d", &iput[i]);
	
	for(int i = n-1; i>0; i--)
	{
		if(iput[i]<iput[i-1]){
			cnt1 = i-1;
			temp = iput[i-1];
			break;
		}
	}
	
	if(cnt1==-1) printf("-1");
	
	else
	{
		int min;
		for(int i = n-1; i>cnt1; i--)
		{
			if(iput[i]<temp) {
			min=i;
			break;
			}
		}
		
		swap(&iput[min], &iput[cnt1]);
		result[cnt1] = iput[cnt1];
	//	printf("%d\n", result[cnt1]);
		sort(iput+cnt1+1, iput+n, desc);
		
		for(int i = cnt1+1; i<n; i++)
			result[i] = iput[i]; 
		for(int i = 0; i<cnt1; i++)
			result[i] = iput[i];
		for(int i = 0; i<n; i++)
		printf("%d ", result[i]);
	}
	 
	return 0;
}

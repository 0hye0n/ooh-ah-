#include <bits/stdc++.h>
 
using namespace std;
int n, m, cnt=0, cnt1 = 0, ck = 0;
int data[10];
int result[10];
int check1[10009][10];

bool checkin[10009];
bool check[10009];

void f(int pos)
{
	if(pos == m)
	{
		for(int i = 0 ; i<m-1; i++)
			if(result[i]>result[i+1]) ck++;
		
		if(ck==0)
		{
			for(int i = 0; i<cnt1; i++){
				ck=0;
				
				for(int j = 0; j<m; j++)
				{	
					if(result[j]!=check1[i][j])ck++;
				}
				
				if(ck==0) break;
			}
			
			if(ck!=0||cnt1==0)
			{
				for(int i = 0; i<m; i++)
					check1[cnt1][i] = result[i];
				cnt1++;
				
				for(int i = 0; i<m; i++)
					printf("%d ", result[i]);
		
				printf("\n");
			}
		}
		
		ck=0;
		return;
	}
	
	for(int i = 0; i<cnt; i++)
	{
		result[pos] = data[i];
		f(pos+1);
	}
	
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i<n; i++)
	{
		int temp;
		scanf(" %d", &temp);
		if(checkin[temp]==false)
		{
			data[cnt] = temp;
			cnt++;
		}
	}
	sort(data, data+cnt);
	
	f(0);
	return 0;
}
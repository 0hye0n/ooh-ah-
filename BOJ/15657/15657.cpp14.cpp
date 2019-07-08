#include <bits/stdc++.h>

using namespace std;

int n, m;
int result[10009];
bool access[10009];
int data[10009];
int acc = 0;

void f(int pos)
{
	
	if(pos == m)
	{
		for(int i =0 ; i < m-1 ; i++)
			if(result[i]>result[i+1]) acc++;
		if(!acc)
		{
		for(int i = 0; i < m; i++)
			printf("%d ", result[i]);
			
		printf("\n");
		}
		acc = 0;
		
		return;
	}

	for(int i = 0; i<n; i++)
	{
				result[pos] = data[i];
				f(pos+1);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i<n; i++)
		scanf(" %d", &data[i]);
	
	sort(data, data+n);
	
	f(0);
		
	return 0;
}
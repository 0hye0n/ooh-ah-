#include <bits/stdc++.h>

using namespace std;

int n, m;
int result[10009];
bool access[10009];
int data[10009];

void f(int pos)
{
	if(pos == m)
	{


		for(int i = 0; i < m; i++)
			printf("%d ", result[i]);
			
		printf("\n");

		return;
	}

	for(int i = 0; i<n; i++)
	{
		if(!access[data[i]])
		{
				result[pos] = data[i];
				access[data[i]] = true; 
				f(pos+1);
				access[data[i]] = false;
		}
		
		
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
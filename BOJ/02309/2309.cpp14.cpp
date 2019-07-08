#include <bits/stdc++.h>

using namespace std;

int result[8];
int iput[10];
bool access[10];
bool check = false;

void f(int pos)
{
	if(check == true)
		return;
		
	if(pos==7)
	{
		int sum = 0;
		for(int i = 0; i<7; i++)
			sum += result[i];
		if(sum==100)
			{
				for(int i = 0; i<7; i++)
					printf("%d\n", result[i]);
				check = true;
			}
		return;
	}
	
	for(int i = 0; i<9; i++)
	{
		if(!access[i])
		{
			result[pos] = iput[i];
			access[i] = true;
			f(pos+1);
			access[i] = false;
		}
	}
}


int main() {
	for(int i = 0; i<9; i++)
		scanf(" %d", &iput[i]);
		
	sort(iput, iput+9);
	f(0);
	return 0;
}
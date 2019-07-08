#include <bits/stdc++.h>

using namespace std;
int pabo[100], result[100], temp[100],t, n;
bool access[100], check = false;
stack<int> data;
void f(int pos, int sum)
{
	if(sum>n)return;
	data.push(pabo[pos]);
	if(sum==n)
	{
		while(!data.empty())
		{
			printf("%d ", data.top());
			data.pop();
		}
		printf("\n");
		check = true;
		return;
	}
	for(int i = pos-1; i>=0; i--)
	{
		f(i , sum+pabo[i]);
		if(check) return;
	}
}

int main() {
	pabo[0] = 0;
	pabo[1] = 1;
	for(int i=2;;i++)
	{
		pabo[i] = pabo[i-1]+pabo[i-2];
		if(pabo[i]>1000000000) break;	
	}

	scanf(" %d", &t);
	while(t--)
	{
		int pos;
		scanf(" %d", &n);
	//	printf("%d\n", n);
		for(pos=0;;pos++)
			if(pabo[pos]>n){pos--;break;}
			f(pos, pabo[pos]);

		
		check = false;
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, k, cnt=0;
bool check = false, access[100009];
int main() 
{
	scanf("%d %d", &n, &k);
	queue <int> bfs;
	bfs.push(n);
	access[n] = true;
	while(!bfs.empty())
	{
		int size = bfs.size();
		while(size--)
		{
			int x = bfs.front();
			bfs.pop();
			if(x==k){check=true;break;}
			if(x-1>=0&&!access[x-1]){bfs.push(x-1);access[x-1]=true;}
			if(x+1<=100000&&!access[x+1]){bfs.push(x+1);access[x+1]=true;}
			if(2*x<=100000&&!access[2*x]){bfs.push(2*x);access[2*x]=true;}
		}
		if(check)break;
		cnt++;
	}
	
	printf("%d\n", cnt);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
int n, w, L;
int truck[1009];
int remain[1009];
int current = 0, cnt = 0;
int front = 0, rear = 0;
int main() {
	scanf("%d %d %d", &n, &w, &L);
	
	for(int i = 0; i<n; i++)
		scanf(" %d", &truck[i]);
		
	int k = 0;
	
	while(1)
	{
		if(k!=0)
		{
			for(int i = front; i<=rear; i++)remain[i]--;
			
			if(remain[front]==0)
			{
				current -= truck[front];
				front++;
			}
		}
			
		
		if(current+truck[k]<=L)
			{
				current += truck[k];
				rear = k;
				remain[k] = w;
				k++;
			}
		
		cnt++;
	
		if(front==n)break;
			
	}
	printf("%d\n", cnt);
	return 0;
}
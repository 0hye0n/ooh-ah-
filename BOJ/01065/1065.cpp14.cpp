#include <bits/stdc++.h>

using namespace std;
int hansu[1000], n;
int temp[3];
int ans = 0;
int main() {
	int cnt;
	scanf(" %d", &n);
	for(cnt = 0;cnt<99;cnt++)hansu[cnt] = cnt+1;
	for(int j = cnt+1;j<1000;j++)
	{
		int num = j, i=0;bool check = false;
		while(num>0){temp[i] = num%10;num /=10;i++;}

		if((temp[2]-temp[1])==(temp[1]-temp[0])){hansu[cnt]=j;cnt++;}
	}
	
	for(int i = 0; i<cnt; i++)
		if(hansu[i]<=n)ans++;
		else break;
		
	printf("%d\n", ans);
	return 0; 
}
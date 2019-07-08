#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int a, b, n, w, cnt=0;
int ansa, ansb;
bool flag = false;
int main()
{
	scanf("%d %d %d %d", &a, &b, &n, &w);
	for(int i = 1, j = n-1; i<n&&j>0; i++,j--)
	{
		int temp = w - i*a;
		if(temp>0&&temp%b==0&&temp/b==j){flag=true;ansa = i;ansb = j;cnt++;}
		if(cnt>1){printf("-1\n");return 0;}
	}
	if(flag)printf("%d %d\n", ansa, ansb);
	else{printf("-1\n");return 0;}
	return 0;
}
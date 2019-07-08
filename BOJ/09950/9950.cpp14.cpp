#include <bits/stdc++.h>
using namespace std;
int l, w, a;
int main() 
{
	while(1)
	{
		scanf("%d %d %d", &l, &w, &a);
		if(l==0&&w==0&&a==0)break;
		if(l==0)l=a/w;
		else if(w==0)w=a/l;
		else if(a==0)a=l*w;
		
		printf("%d %d %d\n", l, w, a);
	}
	
	return 0;
}
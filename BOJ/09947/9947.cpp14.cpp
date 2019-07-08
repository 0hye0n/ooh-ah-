#include <bits/stdc++.h>
using namespace std;
char name1[30], name2[30];
int main() 
{
	while(1)
	{
		scanf("%s %s", name1, name2);
		if(name1[0]=='#'&&name2[0]=='#')break;
		int t, x=0, y=0;scanf(" %d", &t);char a, b;
		for(int i = 0; i<t; i++){
			scanf(" %c %c", &a, &b);
			if(a==b)x++;
			else y++;
		}
		printf("%s %d %s %d\n", name1, x, name2, y);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int t;
char data[59];
int main() {
	scanf("%d", &t);
	for(int i = 0; i<t; i++)
	{
		int check=0;
		scanf(" %s", data);
		for(int j = 0; data[j]&&check>=0; j++)
			{
				if(data[j]=='(') check++;
				else check--;
			}
		if(check==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
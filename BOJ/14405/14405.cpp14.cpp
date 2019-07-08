#include <bits/stdc++.h>
 
using namespace std;

char iput[5009];
int cnt1 = 0, cnt2 = 0, cnt3 = 0;
int main() {
	int len;
	scanf("%s", &iput);
	
	len = strlen(iput);
	
	if(len<=1)
	{
		printf("NO");
		return 0;
	}
	for(int i = 0; i<len-1; i++)
		if(strncmp(iput+i, "pi", 2)==0) cnt1++;
	cnt1*=2;
	for(int i = 0; i<len-1; i++)
		if(strncmp(iput+i, "ka", 2)==0) cnt2++;
	cnt2*=2;	
	for(int i = 0; i<len-2; i++)
		if(strncmp(iput+i, "chu", 3)==0) cnt3++;
	cnt3*=3;
	
	if(len==(cnt1+cnt2+cnt3)) printf("YES");	
	else	printf("NO");
	return 0;
}
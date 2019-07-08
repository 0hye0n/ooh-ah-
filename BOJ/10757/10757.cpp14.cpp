#include <bits/stdc++.h>
using namespace std;
char a[10009];
char b[10009];
int result[10009];
int main() 
{
	scanf("%s %s", a, b);
	int lena = strlen(a), lenb = strlen(b);
	int mx = lena>lenb?lena:lenb;
	
	reverse(a, a+lena);reverse(b, b+lenb);
	for(int i = lenb; i<=mx+5; i++)b[i] = '0';
	for(int i = lena; i<=mx+5; i++)a[i] = '0';
	for(int i = 0; i<mx; i++)
	{
		result[i] += a[i]+b[i]-96;	
		result[i+1] += result[i]/10;
		result[i] %= 10;	
	}
	if(result[mx]!=0)printf("%d", result[mx]);
	for(int i = mx-1; i>=0; i--)printf("%d", result[i]);

	return 0;
}
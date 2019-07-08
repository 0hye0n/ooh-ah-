#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int p = 1000000/10*15;//const 붙여줘야 int fabo[p]이런식으로 가능;;;;;요건 몰랐네;;;; 
int fabo[p];
lld n;
int main() 
{
	fabo[0]=0;fabo[1]=1;
	scanf("%lld", &n);
	for(int i = 2; i<p; i++)
	{
		fabo[i] = fabo[i-1]+fabo[i-2];
		fabo[i] %= 1000000;
	}
	printf("%d\n", fabo[n%p]);
	return 0;
	}
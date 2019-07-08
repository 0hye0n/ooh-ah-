#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int r, b, l, w;
	
	scanf("%d %d", &r, &b);
	
	for(int i = 2; i<=r-6; i+=2)
	{
		if((i/2)*((r-i)/2-2)==b){
		l = i/2+2;
		w = (r-i)/2;
		break;
		}
	}
	
	if(l>w)
	printf("%d %d", l, w);
	
	else
	printf("%d %d", w, l);
	
			
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, hole, possible=0;
	scanf("%d %d", &n, &k);
	for(int i = 0; i<k; i++){
		scanf(" %d", &hole);
		switch(hole)
		{
			case 3:
			case 4:
				possible +=2;
				break;
			case 5:
			case 6:
				possible +=3;
				break;
			case 7:
			case 8:
				possible +=4;
		}
	}
	
	if(possible>=n) printf("YES");
	else printf("NO");
	
	return 0;
}

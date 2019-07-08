#include <bits/stdc++.h>

using namespace std;

unsigned long long a, b, v, current = 0;

int main() {
	
	
	scanf("%lld %lld %lld", &a, &b, &v);
	
	unsigned long long i=0;
	
	i = v/(a-b)+2;
	current = i*(a-b);
	
	int j = 0;
	while(1)
	{
		
		current += b;
		if(current<v)
		{
			i++;
			break;
		}	
		current -=a;
		i--;
	}

	printf("%lld", i);
	return 0;
}



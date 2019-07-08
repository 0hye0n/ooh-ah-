#include<bits/stdc++.h>

using namespace std;
int a, b, c;
int shingyhae(int x, int y)
{
	int sum = 0;
	while(x>0)
	{
		sum += x%y;
		x /=y;
	}
	
	return sum;
}



int main(){
	for(int i = 1000; i<10000; i++)
	{
		a = shingyhae(i, 10);
		b = shingyhae(i, 12);
		c = shingyhae(i, 16);
		
		if(a==b&&b==c&&c==a) printf("%d\n", i);
	}

    return 0;
}
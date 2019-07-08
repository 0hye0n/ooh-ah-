#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int e, s, m;
	int e1=1, s1=1, m1=1;
	int year = 1;
	
	scanf("%d %d %d", &e, &s, &m);
	
	
	while(1)
	{
		if((e==e1)&&(s==s1)&&(m==m1))
			break;
		
		year++;e1++;s1++;m1++;
		e1 %= 16;
		s1 %= 29;
		m1 %= 20;
		
		if(e1==0)
			e1=1;
			
		if(s1==0)
			s1=1;
			
		if(m1==0)
			m1=1;
	}
	
	printf("%d", year);
	
	return 0;
}
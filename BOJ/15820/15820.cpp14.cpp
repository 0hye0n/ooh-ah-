#include <bits/stdc++.h>
using namespace std;

int main() {
	int s1, s2, error = 0, check=0;
	scanf("%d %d", &s1, &s2);
	for(int i = 0; i<s1; i++)
	{
		int tmp1, tmp2;
		scanf(" %d %d", &tmp1, &tmp2);
		if(tmp1!=tmp2) error++;
	}
	if(error==0) check = 1;
	
	for(int i = 0; i<s2; i++)
	{
		int tmp1, tmp2;
		scanf(" %d %d", &tmp1, &tmp2);
		if(tmp1!=tmp2) error++;
	}
	if(error&&(check==1)) printf("Why Wrong!!!");
	else if(error) printf("Wrong Answer");
	else printf("Accepted");
	
	return 0;
}

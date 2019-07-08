#include <bits/stdc++.h>
using namespace std;
char poly[30];
char temp[10];
int main() {
	int pos=0, result = 0;
	scanf(" %s", &poly);
	for(int i = 0; i<strlen(poly); i++)
	{
		if(poly[i]=='x'){
		int j, k;
		j = i-1;k=0;
		while((j>=0)&&((poly[j]!='-')&&(poly[j]!='+')))
		{
			temp[k] = poly[j];
			k++;
			j--;
		}

		if((j==-1)||(poly[j]=='+'))
		{
			if(i==0||(j==i-1))
			result +=1;
			else
				for(int l = 0; l<=k-1; l++)
					result += (temp[l]-48)*pow(10, l);
		}

		else if(poly[j]=='-')
		{
			if(j==i-1)
				result -=1;
			else
			for(int l = 0; l<=k-1; l++)
				result += -((temp[l]-48)*pow(10, l));
		}
			
		}
	}
	printf("%d", result);
	return 0;
}
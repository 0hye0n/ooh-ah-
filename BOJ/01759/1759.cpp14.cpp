#include <bits/stdc++.h>
 
using namespace std;
int l, c;
char text[20];
bool access[20];
char result[20];

int check = 0;

void f(int pos)
{
	if(pos == l)
	{
		if(check!=0&&l-check>=2)
		{
			for(int i = 0; i<l; i++)
				printf("%c", result[i]);
			printf("\n");
	}	
		return;
	}
	
	for(int i = 0; i<c; i++)
	{
		if(l-check<2)
			return;
		
		if(!access[i])
		{
			bool temp;
			if(text[i]=='a'||text[i]=='e'||text[i]=='i'||text[i]=='o'||text[i]=='u')temp = true;
			else temp = false;
			if(pos==0)
			{
				if(temp)check++;
				result[pos] = text[i];
				access[pos] = true;
				f(pos+1);
				access[pos] = false;
				if(temp)check--;
			}
			
			else if(text[i]>result[pos-1])
			{
				if(temp)check++;
				result[pos] = text[i];
				access[pos] = true;
				f(pos+1);
				access[pos] = false;
				if(temp)check--;
			}
		}
	}
}

int main() {
	scanf("%d %d", &l, &c);
	for(int i = 0; i<c; i++)
		scanf(" %c", &text[i]);
	sort(text, text+c);
	f(0);
	return 0;
}

//a -> 97
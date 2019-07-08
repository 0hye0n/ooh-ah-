#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	
	string name[n+1];
	int score[n+1];
	
	for(int i = 0; i<n; i++)
	{
		cin>>name[i];
		scanf("%d", &score[i]);
	}
		
		
	for(int i = 0; i<n; i++)
	{
		cout<<name[i];
		switch(score[i]/10)
		{
			case 10:
				printf(" A+\n");
				break;
			case 9:
				printf(" A");
				if(score[i]%10>=7)
				printf("+");
				printf("\n");
				break;
			case 8:
				printf(" B");
				if(score[i]%10>=7)
				printf("+");
				printf("\n");
				break;
			case 7:
				printf(" C");
				if(score[i]%10>=7)
				printf("+");
				printf("\n");
				break;
			case 6:
				printf(" D");
				if(score[i]%10>=7)
				printf("+");
				printf("\n");
				break;
			default:
				printf(" F\n");
				break;
		}
	}
	
	
	return 0;
}



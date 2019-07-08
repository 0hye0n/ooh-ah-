#include<bits/stdc++.h>

using namespace std;
int data[20];
int main(){
	while(1)
	{
		int cnt = 0;
		int i = 0;
		while(1)
		{
			int temp;
			scanf(" %d", &temp);
			if(temp==0)
				break;
			else if(temp == -1)
				return 0;
			else
				data[i] = temp;
			i++;
		}
		
		sort(data, data+i);
		
		for(int j = 0; j<i; j++)
			for(int k = j+1; k<i; k++)
				if((data[j]*2)==data[k])cnt++;
				
		printf("%d\n", cnt);
	}
	
    return 0;
}
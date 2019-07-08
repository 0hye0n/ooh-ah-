#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, temp;
char init[8][10] = {"", "1", "10", "11", "100", "101", "110", "111"};
char data[8][10] = {"000", "001", "010", "011", "100", "101", "110", "111"};
char input[333339];
int main(){
	scanf("%s", input);int len = strlen(input);
	int i;
	if(len==1&&input[0]=='0')
	{
		printf("0");
		return 0;
	}
	temp = input[0]-'0';
	printf("%s", init[temp]);
	for(i=1; i<len; i++)
	{
		temp = input[i]-'0';
		printf("%s", data[temp]);
	}
	return 0;
}
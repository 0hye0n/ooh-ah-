#include<bits/stdc++.h>

using namespace std;
int n;
long long sum = 0;
int data[1009];
int temp = 0;
int main(){
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++)
		scanf(" %d", &data[i]);	
	sort(data, data+n);
	for(int i = 0; i<n; i++)
	{
		temp = temp+data[i];
		sum = sum+temp;
	}
	printf("%lld", sum);
    return 0;
}
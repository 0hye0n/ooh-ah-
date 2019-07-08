#include<bits/stdc++.h>

using namespace std;
int n;
long long sum = 0;
int data1[59];
int data2[59];
int main(){
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
		scanf(" %d", &data1[i]);
	for(int i = 0; i<n; i++)
		scanf(" %d", &data2[i]);
	sort(data1, data1+n);
	sort(data2, data2+n);
	reverse(data2, data2+n);
	
	for(int i = 0; i<n; i++)
		sum = sum+data1[i]*data2[i];
		
	printf("%d\n", sum);
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
int n;
int data[10009];
int result[4];
int zero=0, ans;
int main(){
	scanf("%d", &n);
	for(int i = 0; i<n ;i++)
		scanf(" %d", &data[i]);
	sort(data, data+n);
	result[0] = data[0]*data[1];
	result[1] = data[n-1]*data[n-2];
	result[2] = data[n-1]*data[n-2]*data[n-3];
	result[3] = data[0]*data[1]*data[n-1];
	
	sort(result, result+4);
	
	printf("%d\n", result[3]);
    return 0;
}
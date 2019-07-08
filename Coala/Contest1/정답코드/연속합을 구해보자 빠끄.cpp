//연속합을 구해보자 빠끄

//연속합 최대 최소
//1<=n<=100000
//각각의 수는 -10000보다 크거나 같고 10000보다 작거나 같다.
//입력은 첫쨰줄 n주어짐 둘쨰줄 부터 n개의 수가 주어짐
//출력은 연속합의 최대 최소 값을 공백으로 구분하여 출력
#include <bits/stdc++.h>
#define MAX 100009
using namespace std;
int n, data[MAX], dp[MAX];
long long mx = -100000009, mn = 100000009;

void mxsolve(){
	for(int i = 1; i<=n; i++){
		dp[i] = data[i-1]+dp[i-1]>data[i-1]?data[i-1]+dp[i-1]:data[i-1];
		mx = mx<dp[i]?dp[i]:mx;
	}
	memset(dp, 0, sizeof(dp));
}

void mnsolve(){
	for(int i = 1; i<=n; i++){
		dp[i] = data[i-1]+dp[i-1]<data[i-1]?data[i-1]+dp[i-1]:data[i-1];
		mn = mn>dp[i]?dp[i]:mn;
	}
	memset(dp, 0, sizeof(dp));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i<n; i++)cin>>data[i];
	mxsolve();
	mnsolve();
	cout<<mx<<" "<<mn;
	return 0;
}
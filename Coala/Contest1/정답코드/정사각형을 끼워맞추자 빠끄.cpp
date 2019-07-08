#include <bits/stdc++.h>

using namespace std;
//제목 : 정사각형을 끼워맞추자 빠끄
// 설명 : 오직 하나 크기의 정사각형으로 직사각형을 채울때 그 최소의 개수를 구하여라
//1<=w,h<=100000
//첫째줄 직사각형의 가로와 세로 크기가 순서대로 주어진다
//출력은 정사각형의 최소 개수를 출력하면 된다.
long long w, h;

long long uclid(long long x, long long y)
{
	long long a = x > y ? x : y;
	long long b = x > y ? y : x;
	long long R = a % b;

	while(R)
	{
		a = b;
		b = R;
		R = a % b;
	} 
	return b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>w>>h;
	long long gcd = uclid(w, h);
	cout<<(w/gcd)*(h/gcd);
	return 0;
}
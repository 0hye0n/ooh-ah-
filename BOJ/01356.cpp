#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
int n, arr[20], l[20], r[20], size;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;

	for(int i = 0;; i++)
	{
		arr[i] = n % 10;
		n /= 10;
		if(n == 0)
		{
			size = i + 1;
			break;	
		}
	}
	bool flag = false;
	l[0] = arr[0];
	r[size - 1] = arr[size - 1];
	for(int i = 1; i < size; i++)l[i] = l[i - 1] * arr[i];
	for(int i = size - 2; i >=0; i--)r[i] = r[i + 1] * arr[i];
	for(int i = 0; i < size - 1; i++){
		if(l[i] == r[i + 1])flag = true;
	}

	if(flag)cout<<"YES";
	else cout<<"NO";

	return 0;
}
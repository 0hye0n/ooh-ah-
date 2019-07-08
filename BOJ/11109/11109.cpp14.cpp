#include <bits/stdc++.h>

using namespace std;
string result[1001];
int main() {
	int t, temp;
	scanf("%d", &t);
	temp = t;
	while(temp)
	{
		int d, n, s, p;
		scanf("%d %d %d %d", &d, &n, &s, &p);
		if((d+n*p)>(n*s)) result[temp-1] = "do not parallelize";
		else if((d+n*p)==(n*s)) result[temp-1] = "does not matter";
		else result[temp-1] = "parallelize";
		temp--;
	}
	for(int i = t-1; i>=0; i--)
		cout<<result[i]<<endl;
	return 0;
}

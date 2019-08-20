#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, m, ans = 2e9;
char data[59][59];

char check1[10][10] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"}; 
char check2[10][10] = {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};

int tochange(int si, int sj)
{
	int cnt1 = 0, cnt2 = 0;

	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
		{
			if(data[si + i][sj + j] != check1[i][j])cnt1++;
			if(data[si + i][sj + j] != check2[i][j])cnt2++;
		}

	return min<int>(cnt1, cnt2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>data[i][j];

	for(int i = 0; i <= n - 8; i++)
		for(int j = 0; j <= m - 8; j++)
		{
			ans = min<int>(ans, tochange(i, j));
		}

	cout<<ans;
	return 0;
}
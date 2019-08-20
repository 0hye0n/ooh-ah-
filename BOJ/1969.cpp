#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

char dna[5] = {'A', 'C', 'G', 'T'}, res[59];
int n, m, cnt[59][5], hd = 0;
vector <vector<int>> ans;

void print()
{	
	for(int i = 0; i < m; i++)
	{
		cout<<dna[ans[i][0]];
	}
	cout<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	ans.resize(m + 1);
	for(int i = 0; i < n; i++)
	{
		string temp;cin>>temp;
		for(int j = 0; j < m; j++)
		{
			switch(temp[j])
			{
				case 'A':
					cnt[j][0]++;
					break;
				case 'C':
					cnt[j][1]++;
					break;
				case 'G':
					cnt[j][2]++;
					break;
				case 'T':
					cnt[j][3]++;
			}
		}
	}

	for(int i = 0; i < m; i++)
	{
		int mx = max<int>({cnt[i][0], cnt[i][1], cnt[i][2], cnt[i][3]});
		hd += n - mx;
		for(int j = 0; j < 4; j++)if(mx == cnt[i][j])ans[i].push_back(j);
	}
	print();
	cout<<hd;


	return 0;
}
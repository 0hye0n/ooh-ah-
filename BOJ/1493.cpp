#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int len[4], n;

vector <pair<int, int>> v;

int find_len2(int length)
{
	for(int i = 1;; i *= 2)
	{
		if(length < i) return i / 2;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>len[0]>>len[1]>>len[2]>>n;

	sort(len, len + 3);

	for(int i = 0; i < n; i++)
	{
		int length, num;cin>>length>>num;
		v.push_back(make_pair((int)pow(2, length), num));
	}

	sort(v.begin(), v.end(), greater<pair<int, int>>());


	while
	

	



	return 0;
}
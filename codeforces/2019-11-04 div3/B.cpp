#include <bits/stdc++.h>

using namespace std;

int q, arr[109];
bool check[109];


int find_index(int tar, int size)
{
	int ret;
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == tar)
		{
			ret = i;
			break;
		}
	}
	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin>>q;
	while(q--)
	{
		memset(check, false, sizeof(check));
		memset(arr, 0, sizeof(arr));

		int n;
		cin>>n;

		for(int i = 0; i < n; i++) cin>>arr[i];

		for(int i = 1; i <= n; i++)
		{
			int idx = find_index(i, n);

			if(idx == i - 1)
			{
				check[idx] = true;
				continue;
			}

			while(idx > 0 && !check[idx - 1] && arr[idx] < arr[idx - 1])
			{
				swap(arr[idx], arr[idx - 1]);
				idx--;
				check[idx] = true;
			}

		}

		for(int i = 0; i < n; i++)cout<<arr[i]<<" ";
		cout<<"\n";
	}

	return 0;
}
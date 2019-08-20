#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, k, pos = 0, ans = 0, task[109], predict[109], plug[109];
bool check[109];

void init()
{
	cin>>n>>k;

	for(int i = 0; i < 109; i++)predict[i] = 2e9;

	for(int i = 0; i < k; i++)cin>>task[i];
}

int findMAX()
{
	int ret = 0;
	for(int i = 1 ; i < pos; i++)
	{
		if(predict[plug[i]] > predict[plug[ret]])ret = i;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	init();

	for(int i = 0; i < k; i++)
	{

		if(pos < n)
		{
			if(!check[task[i]])
			{
				plug[pos] = task[i];
				check[task[i]] = true;
				pos++;
				int flag = false;
				for(int j = i + 1; j < k; j++)
				{
					if(task[j] == task[i])
					{
						flag = true;
						predict[task[i]] = j;
						break;
					}
				}
				if(!flag)predict[task[i]] = 2e9;
			}

			else
			{
				bool flag = false;

				for(int j = i + 1; j < k; j++)
				{
					if(task[j] == task[i])
					{
						flag = true;
						predict[task[i]] = j;
						break;
					}
				}

				if(!flag)predict[task[i]] = 2e9;
			}
		}

		else
		{
			if(!check[task[i]])
			{
				
				ans++;
				int index = findMAX();
				int flag = false;
				check[task[i]] = true;
				check[plug[index]] = false;
				for(int j = i + 1; j < k; j++)
				{
					if(task[j] == plug[index])
					{
						flag = true;
						predict[plug[index]] = j;
						break;
					}
				}

				if(!flag)predict[plug[index]] = 2e9;
				flag = false;
				plug[index] = task[i];

				for(int j = i + 1; j < k; j++)
				{
					if(task[j] == task[i])
					{
						flag = true;
						predict[task[i]] = j;
						break;
					}
				}

				if(!flag)predict[task[i]] = 2e9;
			}
			else
			{
				bool flag = false;

				for(int j = i + 1; j < k; j++)
				{
					if(task[j] == task[i])
					{
						flag = true;
						predict[task[i]] = j;
						break;
					}
				}

				if(!flag)predict[task[i]] = 2e9;
			}
		}
	}

	cout<<ans;

	return 0;
}
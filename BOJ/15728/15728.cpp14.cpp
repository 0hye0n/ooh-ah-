#include <bits/stdc++.h>
 
using namespace std;

struct A
{
	int x, y;
};

bool compare(const A &a, const A &b)
{
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}

int n, k, mx = -100000000, temp, r=0;
int share[109];
int team[109];
bool access[109];
vector<A> data;

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i<n; i++)
		scanf(" %d", &share[i]);
	for(int i = 0; i<n; i++)
		scanf(" %d", &team[i]);
		
	sort(share, share+n);
	sort(team, team+n);
	
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
		{
				temp = share[i]*team[j];
				data.push_back({temp, j});
				r++;
		}
		
		sort(data.begin(), data.end(), compare);
		int l = r-1;
		temp = k;
		if(k!=0)
		{
		
		
		access[data[l].y] = true;
		l--;
		temp--;
		}
		while(1)
		{
			if(temp==0)
				break;
				
			else if(!access[data[l].y])
			{
				access[data[l].y] = true;
				temp--;
			}
			l--;
		}
		
		int tmp;
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++)
			{
				if(!access[j])
				{
					tmp = share[i]*team[j];
					if(mx<tmp)
						mx = tmp;
				}
			}
		
	printf("%d\n", mx);
	
	return 0;
	
}
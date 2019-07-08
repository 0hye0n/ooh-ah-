#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
lld n, mn = 1000000009, s = 1, z = 0;
bool access[19];
vector <pair<lld, lld> > data;

void f(int pos)
{
	for(int i = 0; i<n; i++)
	{
		if(!access[i]&&pos<i&&(log10(s)+log10(data[i].first)<15))
		{
			s *= data[i].first;
			z += data[i].second;
			lld temp = (lld)fabs(s-z);
			if(temp<mn)mn = temp;
			access[i] = true;
			f(i);
			access[i] = false;
			s /=data[i].first;
			z -= data[i].second;
		}
	}	
}
int main()
{
	scanf("%d", &n);
	for(int i; i<n; i++)
	{
		lld a, b;scanf(" %lld %lld", &a, &b);
		data.push_back({a, b});
	}

	f(-1);
	printf("%lld", mn);
	return 0;
}
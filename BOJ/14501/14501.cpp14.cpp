#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
struct A{
	int t;
	int p;
};
vector <A> data;
int n, sum=0, mx=0;
bool access[100];
void f(int pos)
{
	for(int i = pos; i<n; i++){
		if(!access[i]&&(i+data[i].t<=n))
		{
				access[i] = true;
				sum+=data[i].p;
				if(sum>mx)mx=sum;
				f(i+data[i].t);
				sum-=data[i].p;
				access[i] = false;	
		}
	}
	return;
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
	{
		int t, p;scanf(" %d %d", &t, &p);
		data.push_back({t, p});
	}
	f(0);
	printf("%d\n", mx);
	return 0;
}
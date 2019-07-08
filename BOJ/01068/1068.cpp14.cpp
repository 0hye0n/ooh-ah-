#include <bits/stdc++.h>
using namespace std;
struct A{
	int num;
	int parent;
};
vector <A> a;
bool check[100];
int n, rip_x, cnt=0;
int parent[100];
bool compare(const A& a, const A& b)
{if(a.parent!=b.parent) return a.parent<b.parent;
	else return a.num<b.num;}
void f(int pos)
{if(parent[pos]==0)return;
for(int i = 0; i<n; i++)
	if(!check[i])
		if(a[i].parent==pos){check[i] = true;f(i);}}

int main() {
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
	{    int p;
		scanf(" %d", &p);
		a.push_back({i, p});
		if(p==-1)continue;
		parent[p]++;}
	scanf(" %d", &rip_x);
	if(a[rip_x].parent==-1){printf("0\n");return 0;}
	check[rip_x]=true;
	f(rip_x);
	parent[a[rip_x].parent]--;
	for(int i = 0; i<n; i++)if(check[i]){parent[i]=0;}
	for(int i = 0; i<n; i++)if(!check[i]&&parent[i]==0)cnt++;
	if(cnt==0)cnt++;
	printf("%d\n",cnt);
	return 0;
}
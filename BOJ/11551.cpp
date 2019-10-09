#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

struct shop
{
	int l, s, c;
	
	shop(): shop(-1, -1, 0){}
	shop(int l1, int s1, int c1):l(l1), s(s1), c(c1){}

	bool operator <(const shop& a)const{
		if(l != a.l) return l < a.l;
		else if(s != a.s) return s < a.s;
		return c < a.c; 
	}
};

class CompareShop
{
public:
	bool operator()(shop& a, shop& b)
	{
		if(a.l > b.l) return true;
		else if(a.l == b.l && a.c > b.c) return true;
		else if(a.l == b.l && a.c == b.c && a.s > b.s) return true;
		return false;
	}
};


int n, m, arr[100009], prefix[100009];

priority_queue <shop, vector<shop>, CompareShop> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	shop s[100];

	sort(s, s + 100);
	
	return 0;
}
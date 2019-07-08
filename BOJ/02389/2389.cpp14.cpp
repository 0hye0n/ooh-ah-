#include <bits/stdc++.h>

using namespace std;

struct Dot{
	double x, y;
};

double x=0, y=0, learning_rate=0.9, t=0.9, mx;
int n, epoch = 100;
vector <Dot> data;

inline double getdist(double a, double b)
{
	return (a-x)*(a-x)+(b-y)*(b-y);
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(3);
	cout<<fixed;
	cin>>n;
	for(register int i = 0; i < n; i++)
	{
		double t1, t2;cin>>t1>>t2;
		data.push_back({t1, t2});
	}

	while(epoch--)
	{
		mx = -1;
		int index;
		for(int i = 0; i < n; i++)
		{
			double radius = getdist(data[i].x, data[i].y);
			if(mx < radius)
			{
				mx = radius;
				index = i;
			}
		}
		x = (x+t*data[index].x)/(1+t);
		y = (y+t*data[index].y)/(1+t);
		t*=learning_rate;
	}

	cout<<x<<" "<<y<<" "<<sqrt(mx);
	return 0;
}
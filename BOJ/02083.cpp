#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

string name;
int age, weight;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>name>>age>>weight;

	while(name != "#" || age != 0 || weight != 0)
	{
		if(age > 17 || weight >= 80)
		{
			cout<<name<<" Senior\n";
		}
		else cout<<name<<" Junior\n";

		cin>>name>>age>>weight;
	}
	return 0;
}
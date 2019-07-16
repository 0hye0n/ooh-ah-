#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

stack <int> st;
string line;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(getline(cin, line))
	{
		int size = line.length();
		if(size == 1 && line[0] == '.')break;
		bool flag = false;
		for(int i = 0; i < size; i++)
		{
			if(line[i] == '(')st.push(0);
			else if(line[i] == '[')st.push(1);
			else if(line[i] == ')')
			{
				if(st.empty())flag = true;
				else if(st.top() == 0)st.pop();
				else flag = true;
			}
			else if(line[i] == ']')
			{
				if(st.empty())flag = true;
				else if(st.top() == 1)st.pop();
				else flag = true;	
			}

			if(flag)break;
		}

		if(flag || !st.empty())cout<<"no\n";
		else cout<<"yes\n";

		while(!st.empty())st.pop();
	}
	return 0;
}
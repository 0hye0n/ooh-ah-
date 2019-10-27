#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

string data;
bool correct = true, proper = true;


bool check_correct(string a)
{
	//0 : '('
	//1 : ')'
	//2 : +, *, /, -, %
	//3 : a, b, c, d, e, ..., z
	int cnt = 0;
	int len = a.length();

	stack<int> st;
	
	for(int i = 0; i < len; i++)
	{
		if(a[i] == '(')
		{
			if(st.empty())st.push(0);

			else
			{
				if(st.top() == 1 || st.top() == 3) return false;

				else
				{
					st.push(0);
				}
			}
			cnt++;
		}

		else if(a[i] == ')')
		{
			if(st.empty() || st.top() == 0 || st.top() == 2 || cnt == 0) return false;

			else
			{
				st.push(1);
				cnt--;
			}
		}

		else if(a[i] == '+' || a[i] == '*' || a[i] == '/' || a[i] == '-' || a[i] == '%')
		{
			if(st.empty() || st.top() == 0 || st.top() == 2) return false;
			else
			{
				st.push(2);
			}
		}

		else
		{
			if(st.empty()) st.push(3);

			else if(st.top() == 1 || st.top() == 3) return false;
			else st.push(3);
		}
	}

	if(cnt > 0) return false;
	if(st.top() == 2) return false;

	return true;

}

bool check_proper(string a)
{
	int c_cnt = 0;
	stack<int> st;
	int len = a.length();
	for(int i = 0; i < len; i++)
	{
		if(a[i] == '(') st.push(0);
		else if(a[i] == ')')
		{
			int cnt = 0;

			while(st.top() != 0)
			{
				st.pop();
				cnt++;
			}
			st.pop();
			cnt++;
			if(cnt != 4) return false;
			st.push(3);
		}
		else st.push(3);
	}
	if(st.size() == 3) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	getline(cin, data);
	
	int len = data.length();
	for(int i = 0; i < len;)
	{
		if(data[i] == ' ')
		{
			data.erase(data.begin() + i);
			len--;
			continue;
		}
		i++;
	}

	correct = check_correct(data);
	if(!correct) cout<<"error";
	else
	{
		proper = check_proper(data);
		if(proper) cout<<"proper";

		else cout<<"improper";
	}
	

	return 0;
}
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

string input, ans;
map <string, string> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	arr["000"] = "0";
	arr["001"] = "1";
	arr["010"] = "2";
	arr["011"] = "3";
	arr["100"] = "4";
	arr["101"] = "5";
	arr["110"] = "6";
	arr["111"] = "7";
	cin>>input;
	int size = input.length();

	for(int i = size - 1; i >= 0; i -= 3)
	{
		string temp = "";
		if(i - 2 >= 0)
		{
			for(int j = i - 2; j <= i; j++)temp+=input[j];
			ans = arr[temp] + ans;
		}

		else
		{
			for(int j = 0; j < 2 - i; j++)temp+="0";
			for(int j = 0; j <= i; j++)temp+=input[j];
			ans = arr[temp] + ans;
		}
	}

	cout<<ans;
	return 0;
}
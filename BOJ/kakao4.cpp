#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

bool check[209][10], used[10];int mn = 2e9, nn;
vector <int> w, d;

void solve(int pos)
{
    bool flag = false, res[209];
    memset(res, false, sizeof(res));

    int wsize = w.size(), dsize = d.size();

    for(int i = 0; i < nn; i++)
    {
    	for(int j = dsize; j >= pos + 1; j--)res[i] = (res[i] || check[i][j]);

    }

    for(int i = 0; i < wsize; i++)
    {
        if(!res[w[i]])flag = true;
    }

    if(!flag){
        mn = min<int>(mn, dsize - pos);
        return;
    }
    
    if(pos == 0)
    {
    	return;	
    } 
    
    
    for(int i = 0; i < dsize; i++)
    {

    	if(used[i])continue;
    	cout<<"123";
    	used[i] = true;

        for(int j = 0; j < nn; j++)
        {
        	if(check[j])continue;

			for(int k = j; k < j + d[i]; k++)
	        {
	            check[k % nn][pos] = true;
	        }            

	        solve(pos - 1);
            
            for(int k = j; k < j + d[i]; k++)
	        {
	            check[k % nn][pos] = false;
	        }
        }
        used[i] = false;

    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    nn = n; 
    w = weak;
    d = dist;
    solve(d.size());
    int answer = mn;
    return answer;
}

vector<int> weak = {1, 5, 6, 10}, dist = {1, 2, 3, 4};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<solution(12, weak, dist);
	return 0;
}
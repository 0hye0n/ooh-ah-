#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, d, platform[1009];
vector<int> diff;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin>>n>>m>>d;
 
    int tot = n;
    
    for(int i = 0; i < m; i++)
    {
        cin>>platform[i];
        if(platform[i] > 1){
            tot -= platform[i] - 1;
        }
    }
 
    int water = tot - m;
 
    int div = water / (m + 1);
    int mod = water % (m + 1);
    for(int i = 0; i < m + 1; i++) diff.push_back(div);
    for(int i = 0; i < mod; i++)diff[i] += 1;
 
    sort(diff.begin(), diff.end());
 
    if(diff.back() + 1 > d)cout<<"NO";
    else
    {
        cout<<"YES\n";
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < diff[i]; j++) cout<<"0 ";
            for(int j = 0; j < platform[i]; j++)cout<<i + 1<<" ";
        }
        for(int i = 0; i < diff[m]; i++)cout<<"0 ";
    }
    return 0;
}
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false, check = false;
    int m = key.size(), n = lock.size();

    vector<vector<int>> l1(m), l2(m), l3(m), l4(m), cmp(m * 2 + n - 2);

    for(int i = 0; i < m * 2 + n - 2; i++)
    	for(int j = 0; j < m * 2 + n - 2; j++)
    		cmp[i].push_back(0);

   	for(int i = m - 1, k = 0; i < m - 1 + n, k < n; i++, k++)
   		for(int j = m - 1, l = 0; j < m - 1 + n, l < n; j++, l++)
   			cmp[i][j] = lock[k][l];

    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
        {
            l1[i].push_back(key[i][j]);
        }

	for(int i = m - 1, k = 0; i >= 0; i--, k++)
        for(int j = 0; j < m; j++)
        {
            l2[k].push_back(l1[j][i]);
        }


    for(int i = m - 1, k = 0; i >= 0; i--, k++)
        for(int j = 0; j < m; j++)
        {
            l3[k].push_back(l2[j][i]);
        }

    for(int i = m - 1, k = 0; i >= 0; i--, k++)
    	for(int j = 0; j < m; j++)
        {
            l4[k].push_back(l3[j][i]);
        }
    

    for(int i = 0; i <= m + n - 2; i++){
    	for(int j = 0; j <= m + n - 2; j++)
    	{
    		bool flag = true;
    		vector<vector<int>> temp(cmp);

    		for(int k = i; k < i + m; k++)
    			for(int l = j; l < j + m; l++){
    				if(temp[k][l] != l1[k - i][l - j] && temp[k][l] == 0)
    				{
    					temp[k][l] = 1;
    				}

    				else if(temp[k][l] == l1[k - i][l - j] && l1[k - i][l - j] == 1)
    				{
    					flag = false;
    				}
    			}
    		if(!flag) continue;

    		for(int i = m - 1, k = 0; i < m - 1 + n, k < n; i++, k++){
		   		for(int j = m - 1, l = 0; j < m - 1 + n, l < n; j++, l++){
		   			if(temp[i][j] == 0) flag = false;
		   		}
    		}
		   	if(flag) return true;

		   	
    	}
    }

    for(int i = 0; i <= m + n - 2; i++){
    	for(int j = 0; j <= m + n - 2; j++)
    	{
    		bool flag = true;
    		vector<vector<int>> temp(cmp);

    		for(int k = i; k < i + m; k++)
    			for(int l = j; l < j + m; l++){
    				if(temp[k][l] != l2[k - i][l - j] && temp[k][l] == 0)
    				{
    					temp[k][l] = 1;
    				}

    				else if(temp[k][l] == l2[k - i][l - j] && l2[k - i][l - j] == 1)
    				{
    					flag = false;
    				}
    			}
    		
    		if(!flag) continue;

    		for(int i = m - 1, k = 0; i < m - 1 + n, k < n; i++, k++)
		   		for(int j = m - 1, l = 0; j < m - 1 + n, l < n; j++, l++)
		   			if(temp[i][j] == 0) flag = false;
		   	if(flag) return true;

		   	
    	}
    }

    for(int i = 0; i <= m + n - 2; i++){
    	for(int j = 0; j <= m + n - 2; j++)
    	{
    		bool flag = true;
    		vector<vector<int>> temp(cmp);

    		for(int k = i; k < i + m; k++)
    			for(int l = j; l < j + m; l++){
    				if(temp[k][l] != l3[k - i][l - j] && temp[k][l] == 0)
    				{
    					temp[k][l] = 1;
    				}

    				else if(temp[k][l] == l3[k - i][l - j] && l3[k - i][l - j] == 1)
    				{
    					flag = false;
    				}
    			}

    		if(!flag) continue;

    		for(int i = m - 1, k = 0; i < m - 1 + n, k < n; i++, k++)
		   		for(int j = m - 1, l = 0; j < m - 1 + n, l < n; j++, l++)
		   			if(temp[i][j] == 0) flag = false;
		   	if(flag) return true;

		   	
    	}
    }

    for(int i = 0; i <= m + n - 2; i++){
    	for(int j = 0; j <= m + n - 2; j++)
    	{
    		bool flag = true;
    		vector<vector<int>> temp(cmp);

    		for(int k = i; k < i + m; k++)
    			for(int l = j; l < j + m; l++){
    				if(temp[k][l] != l4[k - i][l - j] && temp[k][l] == 0)
    				{
    					temp[k][l] = 1;
    				}

    				else if(temp[k][l] == l4[k - i][l - j] && l4[k - i][l - j] == 1)
    				{
    					flag = false;
    				}
    			}

    		if(!flag) continue;

    		for(int i = m - 1, k = 0; i < m - 1 + n, k < n; i++, k++)
		   		for(int j = m - 1, l = 0; j < m - 1 + n, l < n; j++, l++)
		   			if(temp[i][j] == 0) flag = false;
		   	if(flag) return true;

		   	
    	}
    }

    return answer;
}

int n, m;
vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, lock1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<solution(key, lock1);
	return 0;
}
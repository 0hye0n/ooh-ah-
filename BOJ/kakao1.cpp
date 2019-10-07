#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    
    int size = s.length(), cnt = 1;
    vector <string> v;
    
    for(int i = 1; i <= size; i++)
    {
        string cmp = "", res = "";

        for(int j = 0; j < size; j += i)
        {
            if(j == 0)
            {
                for(int k = j; k < j + i && k < size; k++) cmp += s[k];
                continue;
            }
            
            else
            {
                string temp = "";
                for(int k = j; k < j + i && k < size; k++) temp += s[k];
                if(temp == cmp)
                {
                    cnt++;
                }
                
                else
                {
                	
                    if(cnt > 1)
                    {
                        string num = "";
                        while(cnt)
                        {
                            char t = '0' + cnt % 10;
                            cnt /= 10;
                            num = t + num;
                        }
                        res += num;
                    }

                    res += cmp;
             
                    cmp = temp;
                    cnt = 1;
                }
            }

            
        }
        
        if(cnt > 1)
        {
            string num = "";
            while(cnt)
            {
                char t = '0' + cnt % 10;
                cnt /= 10;
                num = t + num;
            }
            res += num;
        }

        res += cmp;
        cnt = 1;

        
        v.push_back(res);

    }
    int vsize = v.size(), mn = 2e9;
    for(int i = 0; i < vsize; i++)
    {
        mn = min<int>(v[i].length(), mn);
    }
    
    int answer = mn;
    return answer;
}
int n = 1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i < n; i++)
	{
		string temp;cin>>temp;
		cout<<solution(temp)<<"\n";
	}
	
	return 0;
}
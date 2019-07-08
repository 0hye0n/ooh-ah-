#include <bits/stdc++.h>
using namespace std;
 
int len(int a,int b,int c ,int d)
{
    return (c-a)*(c-a)+(b-d)*(b-d);
}
 
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int ans=0;
        set<pair<int,int> > st;//find 이용하기 위해 사용 
        vector<pair<int,int> > vc;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            vc.push_back({x,y});
            st.insert({x,y});
        }
        sort(vc.begin(),vc.end());
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
            	//(x1,y1)
                int a=vc[i].first;
                int b=vc[i].second;
                //(x2,y2)
                int c=vc[j].first;
                int d=vc[j].second;
                //dx,dy를 구해서 나머지 점두개가 존재하는지 찾을 수 있음 
                int dx=c-a;
                int dy=d-b;
                //나머지 점 두개 find함수로 탐색 
                //if문 안의 조건은 3가지 경우로 다르게 표햔될수 있음!! 가상 정사각형을 그리고 dx와 dy를 이용해서 겉에 정사각형을 감싸는 정사각형을 그린후 어떤식으로 찾을 건지 정할 수 있음 
                if(st.find({c+dy,d-dx})!=st.end() && st.find({a+dy, b-dx})!=st.end())
                    ans=max(ans,len(a,b,c,d));
 
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
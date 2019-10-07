#include <bits/stdc++.h>

using namespace std;
struct A
{
   int s, d, idx;
};

bool cmp(const A &a, const A &b)
{
   if(a.s != b.s) return a.s < b.s;
   else if(a.d != a.d) return a.d < b.d;
   return a.idx < b.idx;
}

int n, b;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
vector <pair<int, int> > res;
vector <int> idx, diff;
vector <A> boots;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin>>n>>b;
   if(n <= 2)
   {
      for(int i = 0; i < b; i++)cout<<"1\n";
      return 0;
   }

   for(int i = 0; i < n; i++)
   {
      int f;cin>>f;
      pq.push(make_pair(f, i));
   }

   for(int i = 0; i < b; i++)
   {
      int s, d;cin>>s>>d;
      boots.push_back({s, d, i});
   }

   sort(boots.begin(), boots.end(), cmp);

   while(!pq.empty() && pq.top().first == 0)
   {
      idx.push_back(pq.top().second);
      pq.pop();
   }
   
   int size = idx.size();
   for(int i = 1; i < size; i++)
   {
      diff.push_back(idx[i] - idx[i - 1]);
   }
   sort(diff.begin(), diff.end());

   for(int i = 0; i < b; i++)
   {
      while(!pq.empty() && pq.top().first <= boots[i].s)
      {
         vector<int>::iterator it;
         it = upper_bound(idx.begin(), idx.end(), pq.top().second);
         int mid = it - idx.begin();
         idx.insert(it, pq.top().second);
         pq.pop();
         
         int r = mid + 1;
         int l = mid - 1;
         int tar = idx[r] - idx[l];
         
         it = lower_bound(diff.begin(), diff.end(), tar);
         diff.erase(it);

         it = upper_bound(diff.begin(), diff.end(), idx[r] - idx[mid]);
         diff.insert(it, idx[r] - idx[mid]);
         it = upper_bound(diff.begin(), diff.end(), idx[mid] - idx[l]);
         diff.insert(it, idx[mid] - idx[l]);
      }
      
      if(diff.back() <= boots[i].d)
      {
         res.push_back({boots[i].idx, 1});
      }

      else res.push_back({boots[i].idx, 0});
      
   }
   sort(res.begin(), res.end());
   for(int i = 0; i < b; i++)cout<<res[i].second<<"\n";
   return 0;
}
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef complex<double> base;
typedef long long ll;

void fft(vector <base> &a, bool invert)
{
    int n = sz(a);
    for (int i=1,j=0;i<n;i++){
        int bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len=2;len<=n;len<<=1){
        double ang = 2*M_PI/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for (int i=0;i<n;i+=len){
            base w(1);
            for (int j=0;j<len/2;j++){
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert){
        for (int i=0;i<n;i++) a[i] /= n;
    }
}

void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res)
{
    vector <base> fa(all(a)), fb(all(b));
    int n = 1;
    while (n < max(sz(a),sz(b))) n <<= 1;
    n<<=1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++) res[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}

vector <int> a, b, res;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string t1, t2;
	cin>>t1>>t2;
	int sa = t1.size(), sb = t2.size();
	for(int i = sa-1; i >= 0; i--)a.push_back(t1[i]-'0');
	for(int i = sb-1; i >= 0; i--)b.push_back(t2[i]-'0');
	multiply(a, b, res);
	int siz = res.size();
	for(int i = 0; i<siz-1; i++)
		if(res[i]>=10)
		{
			res[i+1]+=res[i]/10;
			res[i]%=10;
		}
	if(res.back()>=10){res.push_back(res[siz-1]/10);res[siz-1]%=10;}
	while(res.back()==0&&!res.empty())res.pop_back();
	if(res.empty())res.push_back(0);
	reverse(res.begin(), res.end());
	for(auto i : res)cout<<i;
	return 0;
}
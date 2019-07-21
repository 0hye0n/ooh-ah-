#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

typedef complex<double> base;
 
void fft(vector<base> &a, bool invert) {
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
    if (invert) {
        for (int i=0;i<n;i++) a[i] /= n;
    }
}
 
void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res) {
    vector <base> fa(all(a)), fb(all(b));
    int n = 1;
    while (n < max(sz(a),sz(b))) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++) res[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector <int> m, p, res;

	int c;cin>>c;

	while(c--)
	{
		string member, people;cin>>member>>people;
		int msize = member.length(), psize = people.length(), cnt = 0;
		m.resize(msize);
		p.resize(psize * 2);
		for(int i = 0; i < msize; i++)
		{
			if(member[i] == 'F') m[msize - i - 1] = 0;
			else m[msize - i - 1] = 1;
		}
		
		for(int i = psize - 1; i >= 0; i--)
		{
			if(people[i] == 'F')p[i] = 0;
			else p[i] = 1;
			p[i + psize] = 0;
		}
		multiply(p, m, res);

		int size = res.size();
		for(int i = msize - 1; i < psize; i++)if(res[i] == 0)cnt++;
			cout<<cnt<<"\n";
		m.clear();
		p.clear();
		res.clear();
	}
	
	return 0;
}
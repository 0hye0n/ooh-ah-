#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef complex<double> base;

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
	fa.resize(n); fb.resize(n);
	fft(fa,false); fft(fb,false);
	for (int i=0;i<n;i++) fa[i] *= fb[i];
	fft(fa,true);
	res.resize(n);
	for (int i=0;i<n;i++) res[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}

int n, m;
string pp1, pp2;
vector <int> resr, ress, resp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>pp1>>pp2;

	vector <int> r1(2 * n, 0), r2(m, 0), s1(2 * n, 0), s2(m, 0), p1(2 * n, 0), p2(m, 0);

	for(int i = 0; i < n; i++)
	{
		switch(pp1[i])
		{
			case 'R':
			r1[i] = 1;
			break;
			case 'S':
			s1[i] = 1;
			break;
			case 'P':
			p1[i] = 1;
		}
	}

	for(int i = i; i < m; i++)
	{
		switch(pp2[i])
		{
			case 'R':
			r2[m - i - 1] = 1;
			break;
			case 'S':
			s2[m - i - 1] = 1;
			break;
			case 'P':
			p2[m - i - 1] = 1;
		}
	}
	multiply(s1, r2, resr);
	multiply(p1, s2, ress);
	multiply(r1, p2, resp);
	int mx = -1;
	for(int i = m - 1; i < n + m - 1; i++)
	{
		mx = max<int>(mx, resr[i] + ress[i] + resp[i]);
	}
	cout<<mx;
	return 0;
}
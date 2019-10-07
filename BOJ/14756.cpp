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

void multiply(const vector<long long> &a,const vector<long long> &b,vector<long long> &res)
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

long long n, l, m, W;
vector<vector<long long>> lv, nv, res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>l>>m>>W;
	
	lv.resize(m);
	nv.resize(m);
	res.resize(m);

	for(int i = 0; i < m; i++)
	{
		lv[i].resize(2 * n);
		for(int j = 0; j < n; j++)
		{
			cin>>lv[i][j];
			lv[i][j + n] = lv[i][j];
		}
	}
		

	for(int i = 0; i < m; i++){
		nv[i].resize(l);
		for(int j = 0; j < l; j++)
		{
			cin>>nv[i][l - 1 - j];
		}
	}

	for(int i = 0; i < m; i++)
	{
		multiply(lv[i], nv[i], res[i]);
	}

	int cnt = 0;

	for(int i = l - 1; i < n; i++)
	{
		long long ans = 0;
		for(int j = 0; j < m; j++)
		{
			ans += res[j][i];
		}
		if(ans > W)cnt++;
	}

	cout<<cnt;

	return 0;
}
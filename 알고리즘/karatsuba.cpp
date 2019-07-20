#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

void normalize(vector<int> &a)
{
	a.push_back(0);

	int size = a.size();
	for(int i = 0; i < size; i++)
	{
		if(a[i] < 0)
		{
			int borrow = ((int)abs(a[i]) + 9) / 10;
			a[i + 1] -= borrow;
			a[i] += 10 * borrow;
		}
	}

	while(a.size() > 1 && num.back() == 0)a.pop_back();
}

//a*b
vector <int> munltiply(const vector<int>& a, const vector<int>& b)
{
	int asize = a.size(), bsize = b.size();
	vector <int> ret(asize + bsize + 1, 0);

	for(int i = 0; i < asize; i++)
		for(int j = 0; j < bsize; j++)
			ret[i + j] += a[i] * b[j];
	normalize(ret);

	return ret;
}


//a+=b*10^k
void addTo(vector <int>& a, vector <int>& b, int k)
{
	vector<int> temp(k, 0);
	temp.insert(temp.end(), b.begin(), b.end());

	int asize = a.size(), tempsize = temp.size();
	if(asize < tempsize) a.insert(a.end(), tempsize - asize, 0);

	asize = a.size(), tempsize = temp.size();
	int size = min(asize, tempsize);
	for(int i = 0; i < size; i++) a[i] += temp[i];
	normalize(a);
}

//a-=b
void subfrom(vector <int>& a, const vector <int>& b)
{
	int size = b.size();
	for(int i = 0; i < size; i++)a[i] -= b[i];
	normalize(a); 
}

vector <int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	int asize = a.size(), bsize = b.size();

	if (asize < bsize) return karatsuba(b, a);
	
	if(asize == 0 || bsize == 0) return vector<int>();

	if(asize <= 50) return multiply(a, b);

	int half = asize / 2;

	vector <int> a0(a.begin(), a.begin() + half);
	vector <int> a1(a.begin() + half, a.end());
	vector <int> b0(b.begin(), b.begin() + min<int>(half, bsize));
	vector <int> b1(b.begin() + min<int>(half, bsize), b.end());

	vector <int> z2 = karatsuba(a1, b1);
	vector <int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0);addTo(b0, b1, 0);

	vector <int> z1 = karatsuba(a0, b0);
	subfrom(z1, z0);
	subfrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	return 0;
}
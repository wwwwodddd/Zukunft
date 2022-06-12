#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, m, l;
int w[51][51], s;
int f[51][51][51];
long long fac[51];
int pw(int x, int y)
{
	int re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}
int main()
{
	cin >> n >> m >> l;
	for (int i = 0; i < n; i++)
	{
		w[i][0] = 1;
		cin >> w[i][1];
		for (int j = 2; j <= l; j++)
		{
			w[i][j] = (long long)w[i][j - 1] * w[i][1] % p;
		}
		s += w[i][1];
	}
	fac[0] = 1;
	f[0][0][0] = 1;
	for (int i = 1; i <= l; i++)
	{
		fac[i] = fac[i - 1] * pw(i, p - 2) % p;
		f[0][0][0] = (long long)f[0][0][0] * i % p;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			for (int k = 0; k <= l; k++)
			{
				for (int kk = 0; k + kk <= l; kk++)
				{
					int &t = f[i + 1][j + (kk > 0)][k + kk];
					t = (t + (long long)f[i][j][k] * fac[kk] % p * w[i][kk]) % p;
				}
			}
		}
	}
	long long z = f[n][m][l];
	z = z * pw(s, p - 1 - l) % p;
	cout << z << endl;
	return 0;
}
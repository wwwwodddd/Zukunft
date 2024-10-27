#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int d[26];
string s;
int f[5020];
int v[5020];
int g[5020];
int h[5020];
int C(int n, int m)
{
	return (long long)f[n] * v[m] % p * v[n - m] % p;
}
int main()
{
	f[0] = 1;
	v[0] = v[1] = 1;
	for (int i = 2; i < 5010; i++)
	{
		v[i] = (long long)v[p % i] * (p - p / i) % p;
	}
	for (int i = 1; i < 5010; i++)
	{
		f[i] = (long long)f[i - 1] * i % p;
		v[i] = (long long)v[i - 1] * v[i] % p;
	}
	cin >> s;
	for (auto i : s)
	{
		d[i - 'a']++;
	}
	int t = 0;
	g[0] = 1;
	for (int i = 0; i < 26; i++)
	{
		if (d[i] > 0)
		{
			memset(h, 0, sizeof h);
			for (int j = 1; j <= d[i]; j++)
			{
				for (int k = 0; k <= t; k++)
				{
					h[k + j] = (h[k + j] + (long long)g[k] * C(k + j, k) % p * C(d[i] - 1, j - 1)) % p;
				}
			}
			t += d[i];
			swap(g, h);
		}
	}
	int z = 0;
	for (int i = 0; i <= t; i++)
	{
		z = (g[i] + p - z) % p;
	}
	cout << z << endl;
	return 0;
}
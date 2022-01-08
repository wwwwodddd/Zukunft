#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
string s;
int t, z;
int d[30];
int c[5020][5020];
int f[30][5020];
int main()
{
	cin >> s;
	for (int i = 0; i <= s.size(); i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
		}
	}
	for (char i: s)
	{
		d[i - 'a']++;
	}
	f[0][0] = 1;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j <= t; j++)
		{
			for (int k = 0; k <= d[i]; k++)
			{
	            f[i + 1][j + k] = (f[i + 1][j + k] + (long long)f[i][j] * c[j + k][k]) % p;
			}
		}
		t += d[i];
	}
	for (int j = 1; j <= t; j++)
	{
		z = (z + f[26][j]) % p;
	}
	cout << z << endl;
	return 0;
}

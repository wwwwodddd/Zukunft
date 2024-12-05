#include <bits/stdc++.h>
using namespace std;
int n, m, p, z;
int a[30][30];
int b[30][30];
string s;
void mul(int a[30][30], int b[30][30])
{
	int w[30][30] = {};
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < m; k++)
			{
				w[i][j] = (w[i][j] + (long long)a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, w, sizeof w);
}
int main()
{
	cin >> n >> m >> p >> s;
	for (int i = 0, k; i < m; i++)
	{
		for (int j = '0'; j <= '9'; j++)
		{
			for (k = i + 1; k > 0; k--)
			{
				if (s.substr(0, k - 1) == s.substr(i - k + 1, k - 1) && j == s[k - 1])
				{
					break;
				}
			}
			b[i][k]++;
		}
	}
	a[0][0] = 1;
	for (; n > 0; n >>= 1)
	{
		if (n & 1)
		{
			mul(a, b);
		}
		mul(b, b);
	}
	for (int i = 0; i < m; i++)
	{
		z = (z + a[0][i]) % p;
	}
	cout << z << endl;
	return 0;
}
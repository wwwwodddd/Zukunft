#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[3020];
int s[3020];
int f[3020][320];
int p[3020][320];
int suan(int l, int r)
{
	int c = (l + r) / 2;
	return a[c] * (c - l) - (s[c - 1] - s[l - 1]) + (s[r] - s[c]) - a[c] * (r - c);
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for (int j = 1; j <= m; j++)
	{
		p[n + 1][j] = n;
		for (int i = n; i > 0; i--)
		{
			for (int k = p[i][j - 1]; k <= p[i + 1][j]; k++)
			{
				int t = f[k][j - 1] + suan(k + 1, i);
				if (f[i][j] > t)
				{
					f[i][j] = t;
					p[i][j] = k;
				}
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}
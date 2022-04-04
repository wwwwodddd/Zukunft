#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m;
int f[2][5020][2];
int g[2][5020][2];
int main()
{
	cin >> n >> m;
	f[1][m - 1][1] = 1;
	g[1][m - 1][1] = 1;
	f[1][m][0] = 1;
	g[1][m][0] = 0;
	for (long long l = 2; l <= n; l++)
	{
		for (int i = 0; i + l <= n; i++)
		{
			int j = i + l;
			f[l & 1][i][0] = (f[~l & 1][i][0] * l + f[~l & 1][i][1]) % p;
			g[l & 1][i][0] = (g[~l & 1][i][0] * l + g[~l & 1][i][1] + f[~l & 1][i][1]) % p;
			f[l & 1][i][1] = (f[~l & 1][i + 1][1] * l + f[~l & 1][i + 1][0]) % p;
			g[l & 1][i][1] = (g[~l & 1][i + 1][1] * l + g[~l & 1][i + 1][0] + f[~l & 1][i + 1][0]) % p;
		}
	}
	int s = (g[n & 1][0][0] + g[n & 1][0][1] - f[n & 1][0][1]) % p;
	if (s < 0)
	{
		s += p;
	}
	if (s & 1)
	{
		s += p;
	}
	s /= 2;
	cout << s << endl;
	return 0;
}
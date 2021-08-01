#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int t, n, m, l, x, y;
int f[2][5020];
vector<int> a[5020];
int main()
{
	cin >> n >> m >> l;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		a[i].push_back(i);
	}
	f[0][1] = 1;
	for (int i = 1; i <= l; i++)
	{
		int s = 0;
		for (int j = 1; j <= n; j++)
		{
			s = (s + f[(i - 1) & 1][j]) % p;
		}
		for (int j = 1; j <= n; j++)
		{
			f[i & 1][j] = s;
			for (int k : a[j])
			{
				f[i & 1][j] = (f[i & 1][j] + p - f[(i - 1) & 1][k]) % p;
			}
		}
	}
	cout << f[l & 1][1] << endl;
	return 0;
}
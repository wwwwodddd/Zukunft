#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m, x;
int a[100020];
long long f[120];
long long g[120];
int main()
{
	cin >> n >> m;
	for (int j = 1; j <= m; j++)
	{
		g[j] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		swap(f, g);
		cin >> x;
		if (x > 0)
		{
			for (int j = 1; j <= m; j++)
			{
				if (j != x)
				{
					f[j] = 0;
				}
			}
		}
		for (int j = 1; j <= m; j++)
		{
			g[j] = (f[j - 1] + f[j] + f[j + 1]) % p;
		}
	}
	int s = 0;
	for (int j = 1; j <= m; j++)
	{
		s = (s + f[j]) % p;
	}
	cout << s << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int f[200020];
int z;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x != y)
	{
		z--;
		f[x] = y;
	}
}
int b[11][200020];
int main()
{
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n + 5; i++)
		{
			f[i] = i;
			for (int d = 0; d < 11; d++)
			{
				b[d][i] = 0;
			}
		}
		z = n;
		for (int i = 0; i < m; i++)
		{
			int a, d, k;
			cin >> a >> d >> k;
			b[d][a]++;
			b[d][a + d * k]--;
		}
		for (int d = 1; d <= 10; d++)
		{
			for (int i = 1; i <= d; i++)
			{
				int s = 0;
				for (int j = i; j <= n; j += d)
				{
					s += b[d][j];
					if (s > 0)
					{
						U(j, j + d);
					}
				}
			}
		}
		cout << z << endl;
	}
	return 0;
}
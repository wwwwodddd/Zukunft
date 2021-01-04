#include <bits/stdc++.h>
using namespace std;
const int p = 45989;
int n, m, t, s, e, x, y;
int a[120][120];
int b[120][120];
void mul(int a[120][120], int b[120][120])
{
	int w[120][120] = {};
	for (int i = 0; i < m; i++)
	{
		for (int k = 0; k < m; k++)
		{
			if (a[i][k] == 0)
			{
				continue;
			}
			for (int j = 0; j < m; j++)
			{
				w[i][j] = (w[i][j] + (long long)a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, w, sizeof w);
}
vector<int> in[60], ot[60];
int main()
{
	scanf("%d%d%d%d%d", &n, &m, &t, &s, &e);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		ot[x].push_back(i);
		in[y].push_back(i);
		ot[y].push_back(i + m);
		in[x].push_back(i + m);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j: in[i])
		{
			for (int k: ot[i])
			{
				if (j - k != m && k - j != m)
				{
					b[j][k] = 1;
				}
			}
		}
	}
	m *= 2;
	for (int j: ot[s])
	{
		a[0][j] = 1;
	}
	for (t--; t > 0; t >>= 1)
	{
		if (t & 1)
		{
			mul(a, b);
		}
		mul(b, b);
	}
	int z = 0;
	for (int j: in[e])
	{
		z = (z + a[0][j]) % p;
	}
	printf("%d\n", z);
	return 0;
}
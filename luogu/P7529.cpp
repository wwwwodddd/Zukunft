#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, x[50], y[50];
long long c[50][50];
long long C(int x, int y, int z)
{
	if (x < 0)
	{
		return 0;
	}
	return c[x + y + z][x] * c[y + z][y] % mod;
}
long long f[50][50][50][50];
long long F(int x, int y, int z, int w)
{
	if (x > y)
	{
		swap(x, y);
	}
	if (y > z)
	{
		swap(y, z);
	}
	if (x > y)
	{
		swap(x, y);
	}
	return f[x][y][z][w];
}
int d[50][50][50];
int D(int x, int y, int z)
{
	if (x > y)
	{
		swap(x, y);
	}
	if (y > z)
	{
		swap(y, z);
	}
	if (x > y)
	{
		swap(x, y);
	}
	return d[x][y][z];
}
struct N
{
	int x, y, z;
};
vector<N> a[50];
int xm(int x1, int y1, int x2, int y2)
{
	return x1 * y2 - x2 * y1;
}
int sgn(int x)
{
	return (x > 0) - (x < 0);
}
bool in(int i, int j, int k, int l)
{
	int s = 0;
	s += sgn(xm(x[i] - x[l], y[i] - y[l], x[j] - x[l], y[j] - y[l]));
	s += sgn(xm(x[j] - x[l], y[j] - y[l], x[k] - x[l], y[k] - y[l]));
	s += sgn(xm(x[k] - x[l], y[k] - y[l], x[i] - x[l], y[i] - y[l]));
	return (s == 3 || s == -3);
}
void inc(long long &x, long long y)
{
	x = (x + y) % mod;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i <= n; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				for (int l = 0; l < n; l++)
				{
					if (l != i && l != j && l != k)
					{
						if (in(i, j, k, l))
						{
							d[i][j][k]++;
						}
					}
				}
				a[d[i][j][k]].push_back({i, j, k});
				if (d[i][j][k] == 0)
				{
					f[i][j][k][0] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n - 3; i++)
	{
		for (N p : a[i])
		{
			for (int j = 0; j < n; j++)
			{
				if (in(p.x, p.y, p.z, j))
				{
					inc(f[p.x][p.y][p.z][0], F(j, p.y, p.z, 0) * F(p.x, j, p.z, 0) % mod * F(p.x, p.y, j, 0) % mod * C(D(j, p.y, p.z), D(p.x, j, p.z), D(p.x, p.y, j)) % mod);
					for (int k = 1; k <= i; k++)
					{
						for (int l = 0; l < k; l++)
						{
							inc(f[p.x][p.y][p.z][k], F(j, p.y, p.z, l) * F(p.x, j, p.z, 0) % mod * F(p.x, p.y, j, 0) % mod * C(D(j, p.y, p.z) - (k - 1), D(p.x, j, p.z), D(p.x, p.y, j)) % mod);
							inc(f[p.x][p.y][p.z][k], F(j, p.y, p.z, 0) * F(p.x, j, p.z, l) % mod * F(p.x, p.y, j, 0) % mod * C(D(p.x, j, p.z) - (k - 1), D(p.x, p.y, j), D(j, p.y, p.z)) % mod);
							inc(f[p.x][p.y][p.z][k], F(j, p.y, p.z, 0) * F(p.x, j, p.z, 0) % mod * F(p.x, p.y, j, l) % mod * C(D(p.x, p.y, j) - (k - 1), D(j, p.y, p.z), D(p.x, j, p.z)) % mod);
						}
					}
				}
			}
		}
	}
	if (a[n - 3].size() > 0)
	{
		assert(a[n - 3].size() == 1);
		long long z = 0;
		for (int i = 0; i <= n; i++)
		{
			z = (z + f[a[n - 3][0].x][a[n - 3][0].y][a[n - 3][0].z][i]) % mod;
		}
		printf("%lld\n", z * 6 % mod);
	}
	else
	{
		printf("0\n");
	}
	return 0;
}
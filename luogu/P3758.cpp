#include <bits/stdc++.h>
using namespace std;
const int p = 2017;
int n, m, t, x, y;
void mul(int a[31][31], int b[31][31])
{
	int w[31][31] = {};
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; k <= n; k++)
			{
				w[i][j] = (w[i][j] + a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, w, sizeof w);
}
int a[31][31];
int b[31][31];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		b[x][y] = 1;
		b[y][x] = 1;
	}
	for (int i = 0; i <= n; i++)
	{
		a[i][i] = 1;
		b[i][i] = 1;
		b[i][0] = 1;
	}
	cin >> t;
	for (t++; t > 0; t >>= 1)
	{
		if (t & 1)
		{
			mul(a, b);
		}
		mul(b, b);
	}
	cout << a[1][0] << endl;
	return 0;
}
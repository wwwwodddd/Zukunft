#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, n, m, u, v, w, f[100020];
void gao(int x, int y)
{
	for (int i = m; i >= x; i--)
	{
		f[i] = max(f[i], f[i - x] + y);
	}
}
int main()
{
	scanf("%d:%d %d:%d %d", &a, &b, &c, &d, &n);
	m = (c - a) * 60 + d - b;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &w, &v, &u);
		if (u)
		{
			for (int j = 1; j <= u; j *= 2)
			{
				u -= j;
				gao(j * w, j * v);
			}
			gao(u * w, u * v);
		}
		else
		{
			for (int i = w; i <= m; i++)
			{
				f[i] = max(f[i], f[i - w] + v);
			}
		}
	}
	printf("%d\n", f[m]);
	return 0;
}
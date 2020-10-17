#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, w, f[100020];
void gao(int x, int y)
{
	for (int i = m; i >= x; i--)
	{
		f[i] = max(f[i], f[i - x] + y);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &v, &w, &u);
		for (int j = 1; j <= u; j *= 2)
		{
			u -= j;
			gao(j * w, j * v);
		}
		gao(u * w, u * v);
	}
	printf("%d\n", f[m]);
	return 0;
}
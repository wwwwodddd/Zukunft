#include <bits/stdc++.h>
using namespace std;
int n, m, k, a, b, z;
int s[120][120];
bool in(int x, int y)
{
	return 1 <= x && x <= n && 1 <= y && y <= n;
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	z = n * n;
	for (int i = 0; i < m + k; i++)
	{
		scanf("%d%d", &a, &b);
		for (int x = -2; x < 3; x++)
		{
			for (int y = -2; y < 3; y++)
			{
				if ((i >= m || abs(x) + abs(y) < 3) && in(x + a, b + y))
				{
					z -= !s[x + a][b + y]++;
				}
			}
		}
	}
	printf("%d\n", z);
	return 0;
}
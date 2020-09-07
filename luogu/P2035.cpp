#include <bits/stdc++.h>
using namespace std;
int n, m;
int r[1020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &r[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int k = max_element(r + 1, r + n + 1) - r;
		printf("%d\n", k);
		for (int j = 1; j <= n; j++)
		{
			if (j != k)
			{
				r[j] += r[k] / (n - 1) + (j - (j > k) <= r[k] % (n - 1));
			}
		}
		r[k] = 0;
	}
	return 0;
}
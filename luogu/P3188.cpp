#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, x, y;
	while (scanf("%d%d", &n, &m), n + m + 2)
	{
		vector<int> a[40];
		vector<int> b[40];
		int f[2020] = {};
		int s[40] = {};
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			int t = __builtin_ctz(x);
			x >>= t;
			a[t].push_back(x);
			b[t].push_back(y);
			s[t] += x;
		}
		for (int i = 0; m >> i; i++)
		{
			for (int j = 0; j < a[i].size(); j++)
			{
				for(int k = s[i]; k >= a[i][j]; k--)
				{
					f[k] = max(f[k], f[k - a[i][j]] + b[i][j]);
				}
			}
			s[i + 1] += (s[i] + 1) / 2;
			for (int k = 0; k <= s[i + 1]; k++)
			{
				f[k] = f[min(2 * k + (m >> i & 1), s[i])];
			}
		}
		printf("%d\n", f[0]);
	}
	return 0;
}
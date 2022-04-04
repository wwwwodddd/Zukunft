#include <bits/stdc++.h>
using namespace std;
int n, q;
char s[20];
int a[18][18];
int b[18][18];
long long g[262145][18]; // g[i][j] 环包含了 集合i 中的点，以 点j 结束，以 集合i 中最小的点开始
long long f[262145];
long long h[262145];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int t = 1;
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
			a[i][j]--;
			if (t)
			{
				b[i][a[i][j]] = 1;
			}
			if (a[i][j] == i)
			{
				t = 0;
			}
		}
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		cout << b[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	for (int i = 0; i < n; i++)
	{
		g[1 << i][i] = 1;
	}
	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				for (int k = 0; k < n; k++)
				{
					if ((~i >> k & 1) && (1 << k) > (i & -i))
					{
						if (b[k][j]) // 我现在有礼物j，用他去换，第k个人会把礼物k给我吗?
						{
							g[i | 1 << k][k] += g[i][j];
						}
					}
				}
			}
		}
	}
	for (int i = 1; i < 1 << n; i++)
	{
		int k = __builtin_ctz(i); // 环的开始
		for (int j = 0; j < n; j++) // 环的结束
		{
			if (b[k][j])
			{
				if (g[i][j])
				{
					h[i] += g[i][j];
					// cout << i << " " << j << " " << g[i][j] << endl;
				}
			}
		}
	}
	f[0] = 1;
	// for (int i = 1; i < 1 << n; i++)
	// {
	// 	int lb = i & -i; // lowbit 
	// 	int ib = i - lb;
	// 	for (int j = ib;; --j &= ib) // 枚举ib的子集j，子集j不包含lb，子集i^j一定包含lb
	// 	{
	// 		f[i] += f[j] * h[i ^ j];
	// 		if (j == 0)
	// 		{
	// 			break;
	// 		}
	// 	}
	// }

	for (int i = 1; i < 1 << n; i++)
	{
		if (h[i] == 0)
		{
			continue;
		}
		int b = 1;
		while (b <= i)
		{
			b *= 2;
		}
		b -= 1 + i;
		for (int j = b;; --j &= b)
		{
			f[i | j] += h[i] * f[j];
			if (j == 0)
			{
				break;
			}
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%s", s);
		int H = 0, G = 0;
		for (int i = 0; s[i]; i++)
		{
			if (s[i] == 'H')
			{
				H |= 1 << i;
			}
			else
			{
				G |= 1 << i;
			}
		}
		cout << f[H] * f[G] << endl;
	}
	return 0;
}
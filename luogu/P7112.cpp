#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b=2) : b(b), m(ull((L(1) << 64) / b)) {}
	ull reduce(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
}FM;
int n, mod;
int a[600][600];
int main()
{
	scanf("%d%d", &n, &mod);
	FM = FastMod(mod);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
			a[i][j] %= mod;
			if (a[i][j] < 0)
			{
				a[i][j] += mod;
			}
		}
	}
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			while (a[j][i])
			{
				int t = a[i][i] / a[j][i];
				for (int k = 0; k < n; k++)
				{
					a[i][k] += mod - FM.reduce((ull)a[j][k] * t);
					if (a[i][k] >= mod)
					{
						a[i][k] -= mod;
					}
				}
				swap(a[i], a[j]);
				ans = mod - ans;
			}
		}
		ans = FM.reduce((ull)ans * a[i][i]);
	}
	printf("%d\n", ans);
	return 0;
}
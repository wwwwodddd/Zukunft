#include <bits/stdc++.h>
using namespace std;
const int mod = 1000007;
int n, m, x;
int f[101];
int main()
{
	scanf("%d%d", &n, &m);
	f[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			f[j + 1] = (f[j + 1] + f[j]) % mod;
		}
		scanf("%d", &x);
		for (int j = m; j > x; j--)
		{
			f[j] = (f[j] + mod - f[j - x - 1]) % mod;
		}
	}
	printf("%d\n", f[m]);
	return 0;
}
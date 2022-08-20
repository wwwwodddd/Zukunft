#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int t, n, k;
long long f[100020];
long long g[100020];
int main()
{
	f[1] = 8;
	g[1] = 1;
//	for (int i = 2; i < 20; i++)
//	{
//		f[i] = (f[i-1] * 9 + g[i-1]) % p;
//		g[i] = (g[i-1] * 9 + f[i-1]) % p;
//	}

	f[2] = 73;
	for (int i = 3; i < 100010; i++)
	{
		f[i] = (18 * f[i - 1] - 80 * f[i - 2] % p + p) % p;
	}

	f[1] = 9;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &k);
		printf("%lld\n", f[n]);
	}
	return 0;
}

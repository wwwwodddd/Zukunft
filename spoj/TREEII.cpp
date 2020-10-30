#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int t, n = 1010, f[1020];
int main()
{
	f[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1 + i; j <= n; j += i)
		{
			f[j] = (f[j] + f[i]) % mod;
		}
	}
	while (scanf("%d", &n) != EOF)
	{
		printf("Case %d: %d\n", ++t, f[n]);
	}
	return 0;
}
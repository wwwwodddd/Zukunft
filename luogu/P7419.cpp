#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
long long f[1000020], s;
int t, n;
int main()
{
	for (int i = 1; i < 1000010; i++)
	{
		f[i] = (f[i - 1] * 4 + (s * 3 + 4) * s + 1) % p;
		s = (s * 2 + 1) % p;
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		printf("%lld\n", f[n]);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n;
long long zuo(int l, int lc, int r, int rc)
{
	if (lc == rc)
	{
		return 0;
	}
	if (l + 1 == r)
	{
		return (long long)l * (lc - rc);
	}
	int m = (l + r) / 2, mc;
	printf("? %d\n", m);
	fflush(stdout);
	scanf("%d", &mc);
	return zuo(l, lc, m, mc) + zuo(m, mc, r, rc);
}
int main()
{
	scanf("%d", &n);
	printf("! %lld\n", zuo(0, n, 10000001, 0));
	return 0;
}
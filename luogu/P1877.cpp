#include <bits/stdc++.h>
using namespace std;
int n, x, l;
bitset<1001> f, g;
int main()
{
	scanf("%d%d%d", &n, &x, &l);
	f[x] = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		f = f >> x | f << (1000 - l + x) >> (1000 - l);
	}
	for (; ~l && !f[l];)
	{
		l--;
	}
	printf("%d\n", l);
	return 0;
}
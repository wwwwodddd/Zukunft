#include <bits/stdc++.h>
using namespace std;
int f[2520];
int main()
{
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	int n, m, s, x;
	scanf("%d%d", &n, &m);
	s = m * 2;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		s += x;
		for (int j = i; j <= n; j++)
		{
			f[j] = min(f[j], f[j - i] + s);
		}
	}
	printf("%d\n", f[n] - m);
	return 0;
}
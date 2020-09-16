#include <bits/stdc++.h>
using namespace std;
int n, x, f[220];
int main()
{
	scanf("%d", &n);
	memset(f, 0x3f, sizeof f);
	f[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			scanf("%d", &x);
			f[j] = min(f[j], f[i] + x);
		}
	}
	printf("%d\n", f[n]);
	return 0;
}
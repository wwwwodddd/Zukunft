#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
long long f[100020];
int main()
{
	scanf("%d%d", &n, &m);
	f[0] = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		for (int j = m; j >= x; j--)
		{
			f[j] += f[j - x];
		}
	}
	if (f[m] == 0)
	{
		f[m] = -1;
	}
	printf("%lld\n", f[m]);
	return 0;
}
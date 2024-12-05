#include <bits/stdc++.h>
using namespace std;
int64_t f[100020];
int n, m, x;
int main()
{
	scanf("%d%d", &n, &m);
	f[0] = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		for (int j = x; j <= m; j++)
		{
			f[j] += f[j - x];
		}
	}
	printf("%ld\n", f[m]);
	return 0;
}
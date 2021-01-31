#include <bits/stdc++.h>
using namespace std;
int n, m, z;
int a[50020];
int f[50020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0, j = 0; i < n; i++)
	{
		while (j < n && a[j] - a[i] <= m)
		{
			j++;
			f[j] = max(f[j - 1], j - i);
		}
		z = max(z, f[i] + j - i);
	}
	printf("%d\n", z);
	return 0;
}
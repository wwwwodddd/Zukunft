#include <bits/stdc++.h>
using namespace std;
int n, m, l, a[100020];
int main()
{
	scanf("%d%d%d", &l, &m, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n + 1);
	int z = m;
	for (int i = 0, j = 0; i < n; i++)
	{
		while (a[j] - a[i] <= m)
		{
			j++;
		}
		z = min(z, j - i - 1);
	}
	printf("%d\n", z);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, m, s;
int a[100020];
int main()
{
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
	}
	if (n < s || (m > 0 && (a[0] < s || a[m - 1] > n - s)))
	{
		puts("NO");
		return 0;
	}
	for (int i = 0; i + 2 < m; i++)
	{
		if (a[i + 2] - a[i] < s)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (int i = 1; i <= m; i += 2)
	{
		printf("%d ", i);
	}
	printf("%d", m + 1);
	for (int i = m / 2 * 2; i >= 0; i -= 2)
	{
		printf(" %d", i);
	}
	printf("\n");
	return 0;
}
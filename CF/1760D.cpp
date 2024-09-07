#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		a[0] = a[n + 1] = 2e9;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		n = unique(a, a + n + 2) - a - 2;
		int c = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i - 1] > a[i] && a[i] < a[i + 1])
			{
				c++;
			}
		}
		puts(c == 1 ? "YES" : "NO");
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int a[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &k);
		int c = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] % k == 0)
			{
				c++;
			}
		}
		int l = 0, r = n;
		while (l < n && a[l] == k)
		{
			l++;
		}
		while (r > l && a[r - 1] == k)
		{
			r--;
		}
		sort(a + l, a + r);
		if (l >= r)
		{
			printf("0\n");
		}
		else if (a[l] == a[r - 1] || c == n)
		{
			printf("1\n");
		}
		else
		{
			printf("2\n");
		}
	}
	return 0;
}
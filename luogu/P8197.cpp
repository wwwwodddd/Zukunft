#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		vector<int> a(n), b, c, d;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			b.push_back(x);
		}
		c = a;
		d = b;
		sort(c.begin(), c.end());
		sort(d.begin(), d.end());
		if (c != d)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (b[i] == a[j])
				{
					for (int k = j; k > i; k--)
					{
						printf("%d %d\n", k + 1, k);
						swap(a[k], a[k - 1]);
					}
					break;
				}
			}
		}
		printf("0 0\n");
	}
	return 0;
}

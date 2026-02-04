#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[100020];
int b[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b, b + n);
		m = unique(b, b + n) - b;
		for (int i = 0; i < n; i++)
		{
			printf("%ld ", lower_bound(b, b + m, a[i]) - b + 1);
		}
		printf("\n");
	}
	return 0;
}
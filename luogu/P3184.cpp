#include <bits/stdc++.h>
using namespace std;
int n, q, x, y;
int a[100000];
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", upper_bound(a, a + n, y) - lower_bound(a, a + n, x));
	}
	return 0;
}
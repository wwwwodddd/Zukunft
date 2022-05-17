#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[200020];
int p[200020];
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
		p[i] = i;
	}
	for (int i = 0; i < q; i++)
	{
		int x;
		scanf("%d", &x);
		int p1 = p[x];
		int p2 = p[x] + 1;
		if (p1 == n)
		{
			p2 = n - 1;
		}
		swap(a[p1], a[p2]);
		p[a[p1]] = p1;
		p[a[p2]] = p2;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d%c", a[i], i == n ? '\n' : ' ');
	}
	return 0;
}
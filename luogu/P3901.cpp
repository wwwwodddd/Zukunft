#include <bits/stdc++.h>
using namespace std;
int n, q, x, y;
int l[100020];
int p[100020];
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		p[i] = max(p[i - 1], l[x]);
		l[x] = i;
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &x, &y);
		puts(p[y] < x ? "Yes" : "No");
	}
	return 0;
}
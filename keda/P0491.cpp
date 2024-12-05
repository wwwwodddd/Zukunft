#include <bits/stdc++.h>
using namespace std;
int a[2000020];
int q[2000020], b, f;
int n, m;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", a[q[b]]);
		scanf("%d", &a[i]);
		while (b < f && a[q[f - 1]] >= a[i])
		{
			f--;
		}
		q[f++] = i;
		while (q[b] <= i - m)
		{
			b++;
		}
	}
}
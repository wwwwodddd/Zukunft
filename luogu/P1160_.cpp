#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int l[100020];
int r[100020];
bool v[100020];
int main()
{
	scanf("%d", &n);
	l[0] = r[0] = 1;
	l[1] = r[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		scanf("%d%d", &x, &y);
		if (y == 0)
		{
			r[i] = x;
			l[i] = l[x];
			r[l[x]] = i;
			l[x] = i;
		}
		else
		{
			l[i] = x;
			r[i] = r[x];
			l[r[x]] = i;
			r[x] = i;
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (!v[x])
		{
			r[l[x]] = r[x];
			l[r[x]] = l[x];
			v[x] = true;
		}
	}
	for (int i = r[0]; i > 0; i = r[i])
	{
		printf("%d ", i);
	}
	return 0;
}

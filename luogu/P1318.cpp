#include <bits/stdc++.h>
using namespace std;
int n, z;
int a[10020];
int l[10020];
int r[10020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		l[i] = max(l[i - 1], a[i]);
	}
	for (int i = n; i > 0; i--)
	{
		r[i] = max(r[i + 1], a[i]);
		z += min(l[i], r[i]) - a[i];
	}
	printf("%d\n", z);
	return 0;
}
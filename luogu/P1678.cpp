#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100020];
int b[100020];
long long z;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}
	sort(a, a + n);
	sort(b, b + m);
	for (int j = 0, i = 0; j < m; j++)
	{
		while (i < n - 1 && a[i + 1] < b[j])
		{
			i++;
		}
		z += min(abs(b[j] - a[i]), abs(b[j] - a[i + 1]));
	}
	printf("%lld\n", z);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, m, a[100020], z;
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		a[i] = a[i + 1] - a[i];
	}
	sort(a, a + n - 1);
	for (int i = 0; i < n - m; i++)
	{
		z += a[i];
	}
	printf("%d\n", z);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, m, z;
int a[100020];
int b[100020];
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
	int i = 0;
	for (int j = 0; j < m; j++)
	{
		if (i < n && a[i] < b[j])
		{
			i++;
		}
		else
		{
			z += b[j];
		}
	}
	if (i < n)
	{
		z = 0;
	}
	printf("%d\n", z);
	return 0;
}
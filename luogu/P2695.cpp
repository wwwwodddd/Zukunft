#include <bits/stdc++.h>
using namespace std;
int n, m, z;
int a[20020];
int b[20020];
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
	for (int i = 0, j = 0; j < m; j++)
	{
		if (i < n && a[i] <= b[j])
		{
			z += b[j];
			i++;
		}
		if (i == n)
		{
			printf("%d\n", z);
			return 0;
		}
	}
	printf("you died!\n");
	return 0;
}
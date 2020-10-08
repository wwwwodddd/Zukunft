#include <bits/stdc++.h>
using namespace std;
int n, m, z;
int a[50020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0, j = 0; j < n; j++)
	{
		while (a[j] - a[i] > m)
		{
			i++;
		}
		z = max(z, j - i + 1);
	}
	printf("%d\n", z);
	return 0;
}
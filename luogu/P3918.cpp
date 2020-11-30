#include <bits/stdc++.h>
using namespace std;
int n, m, z;
int a[10020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + m);
	n--;
	for (int i = m - 1; i >= 0 && n > 0; i--)
	{
		z += n * a[i];
		n -= 2;
	}
	printf("%d\n", z);
	return 0;
}
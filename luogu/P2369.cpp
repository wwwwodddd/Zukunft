#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int a[400000];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (i == 400000)
		{
			nth_element(a, a + m, a + i);
			n -= i - m;
			i = m;
		}
	}
	sort(a, a + n);
	for (int i = 0; i < m; i++)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}
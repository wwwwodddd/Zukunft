#include <bits/stdc++.h>
using namespace std;
int n, s;
int a[20020];
int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; i++)
	{
		s -= a[i];
		if (s <= 0)
		{
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
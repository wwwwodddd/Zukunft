#include <bits/stdc++.h>
using namespace std;
set<int> s[200020];
int n, m, x;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		for (int j = max(1, -x / i); j <= min(m, (n - x) / i); j++)
		{
			s[j].insert(x + i * j);
		}
	}
	for (int j = 1; j <= m; j++)
	{
		int z = 0;
		while (s[j].find(z) != s[j].end())
		{
			z++;
		}
		printf("%d\n", z);
	}
	return 0;
}
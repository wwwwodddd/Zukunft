#include <bits/stdc++.h>
using namespace std;
int n, a, b;
map<int, int> g;
pair<int, int> z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		g[a]++;
		if (b)
		{
			g[a ^ b]++;
		}
	}
	for (pair<int, int> i: g)
	{
		if (z.second < i.second)
		{
			z = i;
		}
	}
	printf("%d\n", z.first);
	return 0;
}
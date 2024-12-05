#include <bits/stdc++.h>
using namespace std;
map<int, int> g;
int n, x;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		g[x] = i;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		printf("%d\n", g[x]);
	}
	return 0;
}
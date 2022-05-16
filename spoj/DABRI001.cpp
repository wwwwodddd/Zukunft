#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int n, x, z;
unordered_map<int, int> f, g;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		f[x] = max(f[x], f[x - 1] + 1);
		g[x] = max(g[x], max(g[x - 1] + 1, f[x - 2] + 2));
		z = max(z, g[x]);
	}
	printf("%d\n", z);
	return 0;
}
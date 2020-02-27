#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		int x, y, z = 0;
		for (int i = 0; i < n; i += 2)
		{
			scanf("%d%d", &x, &y);
			z ^= __builtin_ctz(((x-1)|(y-1))+1);
		}
		puts(z ? "YES" : "NO");
	}
	return 0;
}
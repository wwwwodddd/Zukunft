#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &x);
		int mn = x, mx = x, z = 1;
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &x);
			if (mn < x && x < mx)
			{
				z = 0;
			}
			mn = min(x, mn);
			mx = max(x, mx);
		}
		puts(z ? "YES" : "NO");
	}
	return 0;
}
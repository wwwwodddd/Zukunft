#include <bits/stdc++.h>
using namespace std;
int t, n, x, y, z;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%d", &n, &x, &y);
		for (int i = 2; i < n; i++)
		{
			scanf("%d", &z);
			x = (long long)x * z % y;
		}
		puts(x % y > 0 ? "No" : "Yes");
	}
	return 0;
}
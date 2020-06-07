#include <bits/stdc++.h>
using namespace std;
int t, n, x, y;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%d", &n, &x, &y);
		y /= __gcd(y, x);
		for (int i = 2; i < n; i++)
		{
			scanf("%d", &x);
			y /= __gcd(y, x);
		}
		puts(y > 1 ? "No" : "Yes");
	}
	return 0;
}
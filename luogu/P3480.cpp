#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[1020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		int z = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if ((n - i) % 2 == 0)
			{
				z ^= a[i] - a[i - 1];
			}
		}
		puts(z ? "TAK" : "NIE");
	}
}
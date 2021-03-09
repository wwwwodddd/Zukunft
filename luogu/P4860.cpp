#include <bits/stdc++.h>
int t, n;
int main()
{
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		puts(n & 3 ? "October wins!" : "Roy wins!");
	}
	return 0;
}
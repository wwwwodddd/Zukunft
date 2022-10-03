#include <bits/stdc++.h>
using namespace std;
int t, n = 1000000;
int f[1000020];
int main()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j * j <= i; j++)
		{
			if (f[i - j * j] == 0)
			{
				f[i] = 1;
				break;
			}
		}
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		puts(f[n] ? "Win" : "Lose");
	}
	return 0;
}
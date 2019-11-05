#include <bits/stdc++.h>
using namespace std;
int f[100020];
int main()
{
	f[0] = 0;
	for (int i = 1; i <= 100000; i++)
	{
		for (int j = 1; j * j <= i; j++)
		{
			f[i] |= !f[i - j * j];
		}
	}
	int t, n;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		puts(f[n] ? "Win" : "Lose");
	}
}

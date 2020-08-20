#include <bits/stdc++.h>
using namespace std;
int n, m;
__int128 f[1001];
void print(__int128 x)
{
	if (x > 9)
	{
		print(x / 10);
	}
	putchar('0' + x % 10);
}
int main()
{
	scanf("%d%d", &n, &m);
	f[0] = 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = i; j <= n; j++)
		{
			f[j] += f[j - i];
		}
	}
	print(f[n]);
	puts("");
	return 0;
}
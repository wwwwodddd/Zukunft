#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= 1 << n; i++)
	{
		int x = i < 1 << n ? i ^ (i >> 1) : 0;
		for (int j = 0; j < n; j++)
		{
			putchar(x >> j & 1 ? 'X' : 'O');
		}
		puts("");
	}
	return 0;
}

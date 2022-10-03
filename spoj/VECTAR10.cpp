#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	while (scanf("%d", &n), n)
	{
		if (n & n - 1)
		{
			printf("%d\n", (n - (1 << (31 - __builtin_clz(n)))) * 2);
		}
		else
		{
			printf("%d\n", n);
		}
	}
	return 0;
}
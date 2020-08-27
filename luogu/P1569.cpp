#include <bits/stdc++.h>
using namespace std;
int f[100020];
int n, s, x, p;
int main()
{
	scanf("%d", &n);
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		s += x;
		if (s >= 0)
		{
			*upper_bound(f, f + n, s) = s;
		}
	}
	if (s < 0)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("%ld\n", upper_bound(f, f + n + 1, s) - f - 1);
	}
	return 0;
}
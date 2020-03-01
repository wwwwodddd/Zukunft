#include <bits/stdc++.h>
using namespace std;
long long v[70], x, z = 1;
bool ins(long long x)
{
	for (int i = 62; i >= 0; i--)
	{
		if (x >> i & 1)
		{
			if (!v[i])
			{
				v[i] = x;
				return true;
			}
			x ^= v[i];
		}
	}
	return false;
}
int n, m;
char s[60];
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		x = 0;
		for (int i = 0; i < m; i++)
		{
			x = x * 2 + (s[i] == 'O');
		}
		if (ins(x))
		{
			z *= 2;
		}
	}
	printf("%lld\n", z % 2008);
	return 0;
}

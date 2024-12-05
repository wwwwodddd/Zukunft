#include <bits/stdc++.h>
using namespace std;
int main()
{
	int f0 = 0, f1 = -1;
	int n, m, x, z = 0;
	char s[4];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d", s, &x);
		if (*s == 'A')
		{
			f0 &= x;
			f1 &= x;
		}
		else if (*s == 'O')
		{
			f0 |= x;
			f1 |= x;
		}
		else
		{
			f0 ^= x;
			f1 ^= x;
		}
	}
	for (int i = 30; i >= 0; i--)
	{
		if (f0 >> i & 1)
		{
			z += 1 << i;
		}
		else if (f1 >> i & 1 && m >> i)
		{
			m -= 1 << i;
			z += 1 << i;
		}
	}
	printf("%d\n", z);
	return 0;
}
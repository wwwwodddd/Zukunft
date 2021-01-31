#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[20000020];
char s[40000020];
int z[40000020];
int main()
{
	scanf("%s%s", c, s);
	m = strlen(s);
	s[m] = '$';
	strcat(s, c);
	n = strlen(s);
	for (int i = 1, l = 0, r = 0; i < n; i++)
	{
		if (i <= r && z[i - l] < r - i + 1)
		{
			z[i] = z[i - l];
		}
		else
		{
			z[i] = max(0, r - i + 1);
			while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			{
				z[i]++;
			}
		}
		if (i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}
	z[0] = m;
	long long a = 0, b = 0;
	for (int i = 0; i < m; i++)
	{
		a ^= (i + 1) * (z[i] + 1LL);
	}
	for (int i = m + 1; i < n; i++)
	{
		b ^= (i - m) * (z[i] + 1LL);
	}
	printf("%lld\n%lld\n", a, b);
	return 0;
}
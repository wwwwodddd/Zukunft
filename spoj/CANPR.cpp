#include <bits/stdc++.h>
using namespace std;
int t, n = 1000000, l;
long long s[1000020];
int main()
{
	for (int i = 1; i <= n; i++)
	{
		s[i] = i;
	}
	for (int i = 2; i <= n; i++)
	{
		if (s[i] == i)
		{
			for (int j = i; j <= n; j += i)
			{
				s[j] = s[j] / i * (i - 1);
			}
		}
		s[i] += s[i - 1];
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &l);
		printf("%lld\n", max(s[n / l] * 2 - 1, 0LL));
	}
	return 0;
}
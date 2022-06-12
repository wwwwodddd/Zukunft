#include <bits/stdc++.h>
using namespace std;
int t, n, k;
char s[100020];
int a[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%s", &n, &k, s);
		int m = 0, c = 0;
		long long z = 0, t = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
			{
				c++;
			}
			else
			{
				a[m++] = c;
				z += c;
			}
		}
		for (int i = 0; i < m - k; i++)
		{
			t += a[i];
		}
		for (int i = max(m - k, 0), j = 0; i <= m; i++)
		{
			while (j < i && a[j] <= k - (m - i))
			{
				t -= a[j++];
			}
			z = min(z, t - (long long)(i - j) * (k - (m - i)));
			t += a[i];
		}
		printf("%lld\n", z);
	}
	return 0;
}
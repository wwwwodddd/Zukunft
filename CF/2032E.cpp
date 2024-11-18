#include <bits/stdc++.h>
using namespace std;
int t, n, m;
long long a[1000020];
long long s[1000020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		m = n / 2;
		for (int i = 0; i < 2 * n; i++)
		{
			s[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			s[i + 1] += a[i] * m;
			s[i + 2] += a[i];
			s[i + 3] -= a[i] * (m + 1);
			s[i + n + 1] -= a[i] * (m + 1);
			s[i + n + 2] += a[i];
			s[i + n + 3] += a[i] * m;
		}
		for (int i = 2; i < 2 * n; i++)
		{
			s[i] += s[i - 2];
		}
		for (int i = 2; i < 2 * n; i++)
		{
			s[i] += s[i - 2];
		}
		for (int i = n; i < 2 * n; i++)
		{
			s[i - n] += s[i];
		}
		for (int i = 0; i < n; i++)
		{
			printf("%lld ", s[i]);
		}
		printf("\n");
	}
	return 0;
}
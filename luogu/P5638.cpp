#include <bits/stdc++.h>
using namespace std;
int n, m;
long long s[1000020], z;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		scanf("%lld", &s[i]);
		s[i] += s[i - 1];
	}
	for (int i = m; i < n; i++)
	{
		z = max(z, s[i] - s[i - m]);
	}
	printf("%lld\n", s[n - 1] - z);
	return 0;
}
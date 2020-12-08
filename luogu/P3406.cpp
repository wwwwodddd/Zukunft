#include <bits/stdc++.h>
using namespace std;
int n, m, l, x, a, b, c;
long long s[100020];
long long z;
int main()
{
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 1; i < m; i++)
	{
		scanf("%d", &x);
		s[min(x, l)]++;
		s[max(x, l)]--;
		l = x;
	}
	for (int i = 1; i < n; i++)
	{
		s[i] += s[i - 1];
		scanf("%d%d%d", &a, &b, &c);
		z += min(a * s[i], b * s[i] + c);
	}
	printf("%lld\n", z);
	return 0;
}
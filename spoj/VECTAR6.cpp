#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t, n;
int a[10000020];
int s[10000020];
int main()
{
	a[0] = 1;
	s[0] = 1;
	for (int i = 1; i <= 10000000; i++)
	{
		a[i] = (long long)s[i - 1] * a[i - 1] % p;
		s[i] = (s[i - 1] + a[i]) % p;
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		printf("%d\n", a[n]);
	}
	return 0;
}
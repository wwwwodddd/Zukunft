#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ss;
int a[10000020];
int l[10000020];
int r[10000020];
int s[10000020];
ll L, R;
ll read()
{
	ll n = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar())
	{
	}
	for (; isdigit(c); c = getchar())
	{
		n = n * 10 + c - '0';
	}
	return n;
}
int main()
{
	n = read();
	s[ss++] = 0;
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		while (a[s[ss - 1]] > a[i])
		{
			l[i] = s[--ss];
		}
		r[s[ss - 1]] = i;
		s[ss++] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		L ^= i * (l[i] + 1LL);
		R ^= i * (r[i] + 1LL);
	}
	printf("%lld %lld\n", L, R);
	return 0;
}
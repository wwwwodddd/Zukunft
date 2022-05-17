#include <bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
ll x[200020];
ll y[200020];
ll xm(int i, int j)
{
	return x[i] * y[j] - x[j] * y[i];
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld", &x[i], &y[i]);
		x[i + n] = x[i];
		y[i + n] = y[i];
	}
	long long s = 0, t = 0;
	for (int i = 0; i < n; i++)
	{
		s += xm(i, i + 1);
	}
	long long z = s;
	int i = 0, j = 0;
	while (i < n && j < 2 * n)
	{
		z = min(z, abs(s - 4 * (t + xm(j, i))));
		if (s - 4 * (t + xm(j, i)) > 0)
		{
			t += xm(j, j + 1);
			j++;
		}
		else
		{
			t -= xm(i, i + 1);
			i++;
		}
	}
	printf("%lld\n", z);
	return 0;
}
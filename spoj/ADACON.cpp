#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int N = 3000010;
int v[N + 10];
ll c[N + 10];
ll s[N + 10];
int p[300020], pc;
int n, x;
int main()
{
	for (int i = 2; i <= 1000010; i++)
	{
		if (v[i] == 0)
		{
			p[pc++] = i;
		}
		for (int j = 0; j < pc && p[j] <= N / i; j++)
		{
			v[i * p[j]] = p[j];
			if (v[i] == p[j])
			{
				break;
			}
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		c[x] += 1;
		s[x] += x;
	}
	for (int i = 0; i < N; i++)
	{
		c[i + 1] += c[i];
		s[i + 1] += s[i];
	}
	ll z = n;
	for (int i = 0; i < pc; i++)
	{
		ll t = s[p[i] / 2];
		for (int j = p[i]; j - p[i] / 2 < 1000010; j += p[i])
		{
			t += (c[j] - c[j - (p[i] + 1) / 2]) * j - (s[j] - s[j - (p[i] + 1) / 2]);
			t += (s[j + p[i] / 2] - s[j]) - (c[j + p[i] / 2] - c[j]) * j;
		}
		z = min(z, t);
	}
	if (c[0] == n)
	{
		z = 2;
	}
	printf("%lld\n", z);
	return 0;
}
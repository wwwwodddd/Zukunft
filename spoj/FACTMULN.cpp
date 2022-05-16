#include <bits/stdc++.h>
using namespace std;
struct Sieve
{
	vector<int> v;
	vector<int> p;
	void init(int n)
	{
		v.resize(n + 1);
		for (int i = 2; i <= n; i++)
		{
			if (!v[i])
			{
				p.push_back(i);
				v[i] = i;
			}
			for (int j = 0; j < p.size() && (long long)i * p[j] <= n; j++)
			{
				v[i * p[j]] = p[j];
				if (v[i] == p[j])
				{
					break;
				}
			}
		}
	}
} p;
int t, n;
int F(int p, int c)
{
	for (int i = p;; i++)
	{
		for (int j = i / p; j > 0; j /= p)
		{
			c -= j;
		}
		if (c <= 0)
		{
			return i;
		}
	}
}
int main()
{
	p.init(40000);
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		int z = 1;
		for (int i: p.p)
		{
			int c = 0;
			while (n % i == 0)
			{
				c++;
				n /= i;
			}
			if (c > 0)
			{
				z = max(z, F(i, c));
			}
			if (i * i > n)
			{
				break;
			}
		}
		if (n > 1)
		{
			z = max(z, F(n, 1));
		}
		printf("%d\n", z);
	}
	return 0;
}
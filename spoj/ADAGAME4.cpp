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
int t, n = 20000000;
int f[20000020];
int s[20000020];
int main()
{
	p.init(n);
	s[1] = s[2] = 1;
	f[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (p.v[i] == p.v[i / p.v[i]])
		{
			f[i] = f[i / p.v[i]] * 2 - f[i / p.v[i] / p.v[i]];
		}
		else
		{
			f[i] = f[i / p.v[i]] * 2;
		}
		s[i + 1] = s[i] + (s[i] - s[i - f[i]] == 0);
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		puts(s[n + 1] - s[n] ? "Vinit" : "Ada");
	}
	return 0;
}
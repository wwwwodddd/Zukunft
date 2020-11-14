#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, l;
long long z, s, t;
map<int, int> g;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		z += abs(a - b);
		if ((a ^ b) < 0)
		{
			g[0] += 1;
			g[b] -= 2;
			g[2 * b] += 1;
		}
		else if (abs(a) < abs(b) && abs(a) < abs(a - b))
		{
			g[2 * a] += 1;
			g[b] -= 2;
			g[2 * b - 2 * a] += 1;
		}
	}
	for (pair<int, int> i: g)
	{
		t += (i.first - l) * c;
		s = max(s, t);
		l = i.first;
		c += i.second;
	}
	printf("%lld\n", z - s);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
set<int> s;
int n, m, k, g, p;
int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x;
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	g = gcd(n, k);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &p);
		s.insert(p % g);
	}
	printf("%lu\n", n - n / g * s.size());
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, m, c;
int a[200020];
map<int, int> g;
long long z;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0, j = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		c += !g[a[i]]++;
		while (c > m)
		{
			c -= !--g[a[j++]];
		}
		z += i - j + 1;
	}
	printf("%lld\n", z);
	return 0;
}
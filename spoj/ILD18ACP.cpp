#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m, x, y;
vector<int> a[N];
bitset<N> b[N];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		if (x == y || b[x][y])
		{
			continue;
		}
		a[x].push_back(y);
		a[y].push_back(x);
		b[x][y] = 1;
		b[y][x] = 1;
	}
	long long z = 0;
	for (int i = 1; i <= n; i++)
	{
		bitset<N> s;
		for (int j: a[i])
		{
			s |= b[j];
		}
		z += max(int(s.count()) - 1, 0);

	}
	printf("%lld\n", z / 2);
	return 0;
}
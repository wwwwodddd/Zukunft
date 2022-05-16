#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[100000];
int y[100000];
int d[100000];
bitset<100000> b[100000];
long long z;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		z += d[x[i]]++;
		z += d[y[i]]++;
		b[x[i]][y[i]] = 1;
		b[y[i]][x[i]] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		z -= (b[x[i]] & b[y[i]]).count();
	}
	printf("%lld\n", z);
	return 0;
}
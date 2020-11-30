#include <bits/stdc++.h>
using namespace std;
int n, m, x;
long long z;
int main()
{
	scanf("%d%d", &n, &m);
	for (int k = 1; k > -2; k -= 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &x);
				z += k * x * (i * i + j * j);
			}
		}
	}
	printf("%lld\n", z / 2);
	return 0;
}
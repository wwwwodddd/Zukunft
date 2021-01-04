#include <bits/stdc++.h>
using namespace std;
int n, x, y;
long long z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++)
	{
		scanf("%d%d", &x, &y);
		z += i < n ? y - x : x - y;
	}
	printf("%lld\n", z);
	return 0;
}
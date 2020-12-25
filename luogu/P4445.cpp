#include <bits/stdc++.h>
using namespace std;
int n, l, x;
long long z;
int main()
{
	scanf("%d%d", &n, &l);
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &x);
		z += max(l, x);
		l = x;
	}
	printf("%lld\n", z);
	return 0;
}
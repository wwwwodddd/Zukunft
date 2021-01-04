#include <bits/stdc++.h>
using namespace std;
int n, k, x;
int a[1000020];
int s, z;
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		s += x;
		z = max(z, s);
		s -= a[i % k];
		a[i % k] = x;
	}
	printf("%d\n", z);
	return 0;
}
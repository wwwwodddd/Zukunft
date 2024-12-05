#include <bits/stdc++.h>
using namespace std;
int v[3000020];
int n, p;
int main()
{
	scanf("%d%d", &n, &p);
	v[1] = 1;
	printf("%d\n", 1);
	for (int i = 2; i <= n; i++)
	{
		v[i] = (long long)v[p % i] * (p - p / i) % p;
		printf("%d\n", v[i]);
	}
}
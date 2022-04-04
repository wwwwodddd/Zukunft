#include <bits/stdc++.h>
using namespace std;
int n, l;
int p[100020];
int t[100020];
long long z = 0;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
		p[i] -= t[i];
		if (p[i] > l)
		{
			z += p[i] - l;
		}
		l = p[i];
	}
	if (l < 0)
	{
		z -= l;
	}
	printf("%lld\n", z);
	return 0;
}
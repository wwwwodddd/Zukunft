#include <bits/stdc++.h>
using namespace std;
int n;
int h[300020];
long long z, s;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &h[i]);
		s += h[i];
	}
	sort(h, h + n);
	z = s;
	for (int i = 0; i < n; i++)
	{
		z = min(z, s - (long long)(n - i) * h[i]);
	}
	printf("%lld\n", z);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, x;
long long s, t;
int main()
{
	scanf("%d", &n);
	s = n * (n + 1LL) / 2;
	t = n * (n + 1LL) * (2 * n + 1) / 6;
	for (int i = 2; i < n; i++)
	{
		scanf("%d", &x);
		s -= x;
		t -= (long long)x * x;
	}
	long long aminusb = sqrt(2 * t - s * s);
	printf("%lld %lld\n", (s - aminusb) / 2, (s + aminusb) / 2);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, x, ss;
long long s[1000020];
long long t[1000020];
long long z;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		while (ss > 0 && x > s[ss])
		{
			z += i - t[ss] + 1;
			ss--;
		}
		if (ss > 0)
		{
			z += i - t[ss] + 1;
		}
		s[++ss] = x;
		t[ss] = i;
	}
	printf("%lld\n", z);
	return 0;
}

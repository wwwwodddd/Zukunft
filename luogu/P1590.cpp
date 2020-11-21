#include <bits/stdc++.h>
using namespace std;
long long F(long long n)
{
	long long t = 1, s = 1;
	while (t * 10 < n)
	{
		t *= 10;
		s *= 9;
	}
	long long re = 0;
	for (; t > 0; t /= 10, s /= 9)
	{
		for (int j = 0; j < n / t % 10; j++)
		{
			if (j != 7)
			{
				re += s;
			}
		}
		if (n / t % 10 == 7)
		{
			break;
		}
	}
	return re;
}
int main()
{
	int t;
	long long n;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%lld", &n);
		printf("%lld\n", F(n + 1) - 1);
	}
	return 0;
}
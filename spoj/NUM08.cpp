#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		long long n;
		scanf("%lld", &n);
		long long a[66] = {};
		long long b[66] = {};
		int c = 0;
		for (long long i = 2; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				a[c] = i;
				while (n % i == 0)
				{
					b[c]++;
					n /= i;
				}
				c++;
			}
		}
		if (n > 1)
		{
			a[c] = n;
			b[c++] = 1;
		}
		long long ans = 1;
		for (int i = 0; i < c; i++)
		{
			long long sum = 1;
			long long tmp = 1;
			printf("%lld %lld\n", a[i], b[i]);
			for (int j = 0; j < b[i]; j++)
			{
				tmp *= a[i];
				sum += tmp;
			}
			ans *= sum;
		}
		printf("Sum Of Divisiors: %lld\n\n", ans);
	}
	return 0;
}

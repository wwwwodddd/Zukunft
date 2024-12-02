#include <bits/stdc++.h>
using namespace std;
int n, q;
long long x[200020];
long long s[200020];
long long query(long long a, long long b)
{
	int l = 0;
	int r = n - 1;
	while (l < r) // you don't have to use binary search, it overkills
	{
		int m = (l + r) / 2;
		if ((n - m) * b < m * a) // if x[m-1] is better than x[m]
		{
			r = m - 1;
		}
		else if ((n - m - 1) * b > (m + 1) * a) // if x[m+1] is better than x[m]
		{
			l = m + 1;
		}
		else // if x[m] is better than x[m-1] and x[m+1]
		{
			l = r = m;
		}
	}
	long long z = (l * x[l] - s[l]) * a + (s[n] - s[l] - (n - l) * x[l]) * b; // compute the answer
	return z;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &x[i]);
	}
	sort(x, x + n);
	for (int i = 0; i < n; i++)
	{
		s[i + 1] = s[i] + x[i]; // compute some prefix sum
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%lld\n", query(a, b)); // solve it in the function
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, s, z, a[301];
bitset<100001> f;
int main()
{
	f[0] = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		s += a[i];
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--)
	{
		f |= f << a[i];
		for (int j = s / 2 + 1; j <= s / 2 + a[i]; j++)
		{
			if (f[j])
			{
				z = max(z, j);
			}
		}
	}
	printf("%d\n", z);
	return 0;
}
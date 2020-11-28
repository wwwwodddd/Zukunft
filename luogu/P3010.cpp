#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000;
int n, x, s;
int f[500001];
int main()
{
	scanf("%d", &n);
	f[0] = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		s += x;
		for (int j = s; j >= x; j--)
		{
			f[j] = (f[j] + f[j - x] - 1) % mod + 1;
		}
	}
	for (int i = s / 2; i >= 0; i--)
	{
		if (f[i] > 0)
		{
			printf("%d\n%d\n", s - i - i, f[i] % mod);
			break;
		}
	}
	return 0;
}
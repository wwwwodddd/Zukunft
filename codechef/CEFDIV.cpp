#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int t, n, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		int f[2][2] = {};
		f[0][0] = f[0][1] = 1;
		int s = 0, z = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			s = (s + x) & 1;
			z = (f[1 - s][0] + f[s][1]) % p;
			f[s][0] = (f[s][0] + f[s][1]) % p;
			f[s][1] = (f[s][1] + f[1 - s][0]) % p;
		}
		printf("%d\n", z);
	}
	return 0;
}
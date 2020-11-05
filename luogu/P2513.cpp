#include <bits/stdc++.h>
using namespace std;
const int mod = 10000;
int n, m;
int s[1020];
int main()
{
	scanf("%d%d", &n, &m);
	s[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			s[j] = (s[j] + s[j - 1]) % mod;
		}
		for (int j = m; j >= i; j--)
		{
			s[j] = (s[j] + mod - s[j - i]) % mod;
		}
	}
	printf("%d\n", s[m]);
	return 0;
}
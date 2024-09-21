#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int f[1020];
char s[1020];
int n;
int main()
{
	scanf("%d", &n);
	f[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		for (int j = 1; j <= n; j++)
		{
			if (s[j] == '.')
			{
				f[j] = (f[j] + f[j - 1]) % p;
			}
			else
			{
				f[j] = 0;
			}
		}
	}
	printf("%d\n", f[n]);
	return 0;
}
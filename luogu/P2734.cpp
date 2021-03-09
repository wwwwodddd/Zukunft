#include <bits/stdc++.h>
using namespace std;
int n, s[120], f[120][120];
int main()
{
	scanf("%d", &n);
	for (int j = 1; j <= n; j++)
	{
		scanf("%d", &s[j]);
		s[j] += s[j - 1];
		for (int i = j; i >= 0; i--)
		{
			f[i][j] = s[j] - s[i] - min(f[i + 1][j], f[i][j - 1]);
		}
	}
	printf("%d %d\n", f[0][n], s[n] - f[0][n]);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int f[25] = {-1, 1};
int a, b, n, m, x;
int main()
{
	scanf("%d%d%d%d", &a, &n, &m, &x);
	for (int i = 2; i <= n + 1; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	b = (m - a * (f[n - 1] + 1)) / (f[n] - 1);
	printf("%d\n", a * (f[x] + 1) + b * (f[x + 1] - 1));
	return 0;
}
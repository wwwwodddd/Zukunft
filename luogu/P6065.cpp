#include <bits/stdc++.h>
using namespace std;
int n, f[1000020];
int main()
{
	scanf("%d", &n);
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1];
		if (i % 2 == 0)
		{
			f[i] = (f[i] + f[i / 2]) % 1000000000;
		}
	}
	printf("%d\n", f[n]);
	return 0;
}
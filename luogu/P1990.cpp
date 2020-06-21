#include <bits/stdc++.h>
using namespace std;
int n, f[93000] = {1, 1, 2};
int main()
{
	scanf("%d", &n);
	n %= 93000;
	for (int i = 3; i <= n; i++)
	{
		f[i] = (2*f[i-1] + f[i-3]) % 10000;
	}
	printf("%d\n", f[n]);
	return 0;
}
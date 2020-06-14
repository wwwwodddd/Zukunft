#include <bits/stdc++.h>
using namespace std;
int n, k, p = 5000011;
int f[100020];
int main()
{
	scanf("%d%d", &n, &k);
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		f[i] = (f[i - 1] + (i > k ? f[i - k - 1] : 1)) % p;
	}
	printf("%d\n", f[n]);
	return 0;
}
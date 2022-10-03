#include <bits/stdc++.h>
using namespace std;
int f[1000020];
int t, n;
int main()
{
	f[0] = f[2] = 1;
	for (int i = 3; i <= 1000000; i++)
	{
		f[i] = (f[i - 2] + f[i - 3]) % 1000000007;
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		printf("%d\n", f[n]);
	}
	return 0;
}
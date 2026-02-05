#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("%lld\n", i * (i + 1LL) / 2);
	}
	return 0;
}
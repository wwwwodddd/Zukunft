#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		printf("%d\n", (n - (n + m - 1) / m + 1) & 1);
	}
	return 0;
}
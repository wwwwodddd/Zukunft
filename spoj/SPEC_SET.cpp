#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &k);
		int z = 0;
		if (k > 1)
		{
			for (; n; n /= -k)
			{
				z += n;
			}
		}
		printf("%d\n", z);
	}
	return 0;
}
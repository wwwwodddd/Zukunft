#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t, n;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		if (n & 1)
		{
			printf("%d\n", (n + 1) * (2 * n * n + 3 * n - 1) / 8);
		}
		else
		{
			printf("%d\n", n * (n + 2) * (2 * n + 1) / 8);
		}
	}
	return 0;
}
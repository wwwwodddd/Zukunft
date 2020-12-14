#include <bits/stdc++.h>
using namespace std;
int main()
{
	int l = 1;
	int r = 1000000000;
	while (l <= r)
	{
		int m = (l + r) / 2, x;
		printf("%d\n", m);
		fflush(stdout);
		scanf("%d", &x);
		if (x == -1)
		{
			l = m + 1;
		}
		else if (x == 1)
		{
			r = m - 1;
		}
		else
		{
			break;
		}
	}
	return 0;
}
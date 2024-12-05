#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	scanf("%d", &m);
	for (int i = sqrt(2 * m); i > 1; i--)
	{
		if (2 * m % i == 0 && (i + 2 * m / i) & 1)
		{
			printf("%d %d\n", (2 * m / i - i + 1) / 2, (2 * m / i + i - 1) / 2);
		}
	}
	return 0;
}
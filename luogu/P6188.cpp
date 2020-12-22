#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = n / 14; i >= 0; i--)
	{
		for (int j = 0; j < 3 && i * 14 + j * 4 <= n; j++)
		{
			if ((n - i * 14 - j * 4) % 3 == 0)
			{
				printf("%d %d %d\n", i, i + j, i + (n - i * 14 - j * 4) / 3);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}
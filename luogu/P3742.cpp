#include <bits/stdc++.h>
using namespace std;
int n;
char x[120], y[120];
int main()
{
	scanf("%d%s%s", &n, x, y);
	for (int i = 0; i < n; i++)
	{
		if (x[i] < y[i])
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%s\n", y);
	return 0;
}
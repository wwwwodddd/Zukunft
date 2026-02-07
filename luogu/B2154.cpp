#include <bits/stdc++.h>
using namespace std;
int n, d[10];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int y = i;
		while (y > 0)
		{
			d[y % 10]++;
			y /= 10;
		}
	}
	printf("%d\n", d[1]);
	return 0;
}
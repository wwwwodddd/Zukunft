#include <bits/stdc++.h>
using namespace std;
int n, x, c;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x == c + 1)
		{
			c++;
		}
	}
	printf("%d\n", c > 0 ? n - c : -1);
	return 0;
}
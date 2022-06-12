#include <bits/stdc++.h>
using namespace std;
int t, n, x, a, b;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		a = b = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			if (x == 1)
			{
				a++;
			}
			else
			{
				b++;
			}
		}
		if (n & 1)
		{
			puts(abs(a - b) <= 1 ? "Yes" : "No");
		}
		else if (n % 4 == 2)
		{
			puts(abs(a - b) <= 2 ? "Yes" : "No");
		}
		else
		{
			puts(abs(a - b) <= 0 ? "Yes" : "No");
		}
	}
	return 0;
}
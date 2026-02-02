#include <bits/stdc++.h>
using namespace std;
int t, x, y;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &x, &y);
		if (x + y == 3)
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}
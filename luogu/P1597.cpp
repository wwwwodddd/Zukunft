#include <bits/stdc++.h>
int c[999];
char a, b;
int main()
{
	while (scanf("%c:=%c;", &a, &b) != EOF)
	{
		c[a] = isdigit(b) ? b - 48 : c[b];
	}
	printf("%d %d %d\n", c[97], c[98], c[99]);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
char s[40001];
int main()
{
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 1; i < n; i++)
	{
		scanf("%s", s + i * n);
	}
	printf("%d", n);
	for (int i = 0, c = '0', x = 0; i <= n * n; i++)
	{
		if (s[i] == c)
		{
			x++;
		}
		else
		{
			printf(" %d", x);
			x = 1;
			c ^= 1;
		}
	}
	puts("");
	return 0;
}
#include <stdio.h>
int n, t, x, z;
int main()
{
	scanf("%d", &n);
	for (scanf("%d", &t); t--;)
	{
		scanf("%d", &x);
		if (x != 1)
		{
			printf("GIVE GUY %d GUY 1\n", x);
		}
	}
	scanf("%*d");
	for (scanf("%d", &t); t--;)
	{
		scanf("%d", &x);
		printf("GIVE GIRL %d GUY 1\n", x);
	}
	for (int i = 2; i <= n; i++)
	{
		printf("GIVE GUY 1 GUY %d\n", i);
		printf("ENTER GUY %d\n", i);
		puts("ENTER GUY 1");
		printf("GIVE GUY %d GUY 1\n", i);
		puts("EXIT GUY 1");
	}
	puts("ENTER GUY 1");
	return 0;
}

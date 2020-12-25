#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	if (n < 9)
	{
		puts("0");
	}
	else if (n == 9)
	{
		puts("8");
	}
	else
	{
		printf("72");
		for (int i = 10; i < n; i++)
		{
			printf("0");
		}
		puts("");
	}
	return 0;
}
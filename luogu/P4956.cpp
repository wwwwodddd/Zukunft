#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	n /= 364;
	if (n > 103)
	{
		printf("%d\n%d\n", 98 + (n - 98) % 3, (n - 98) / 3);
	}
	else
	{
		printf("%d\n%d\n", n - 3, 1);
	}
	return 0;
}
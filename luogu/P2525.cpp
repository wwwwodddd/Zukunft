#include <bits/stdc++.h>
using namespace std;
int n, a[9];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	if (prev_permutation(a, a + n))
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
		}
	}
	else
	{
		printf("ERROR\n");
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, z;
int a[1000000];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (i >= n / 2 && a[i] == a[i - n / 2])
		{
			z += 2;
		}
	}
	printf("%d\n", z);
	return 0;
}
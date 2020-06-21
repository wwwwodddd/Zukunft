#include <bits/stdc++.h>
using namespace std;
int n, a[128];
int main()
{
	scanf("%d", &n);
	n = 1 << n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("%d\n", max_element(a, a + n / 2) - max_element(a, a + n) + max_element(a + n / 2, a + n) - a + 1);
	return 0;
}
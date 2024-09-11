#include <bits/stdc++.h>
using namespace std;
int n;
int a[300020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int i = n, mx = 0;
	while (i-- > 0)
	{
		if (a[i] + n < mx)
		{
			break;
		}
		mx = max(mx, a[i] + n - i);
	}
	printf("%d\n", n - i - 1);
	return 0;
}

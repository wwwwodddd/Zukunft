#include <bits/stdc++.h>
using namespace std;
int n, c;
int a[100020];
long long s;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] < 0)
		{
			a[i] = -a[i];
			c++;
		}
		s += a[i];
	}
	if (c & 1)
	{
		s -= 2 * *min_element(a, a + n);
	}
	printf("%lld\n", s);
	return 0;
}

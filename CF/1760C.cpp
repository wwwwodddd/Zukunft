#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200020];
int s[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &s[i]);
			a[i] = -s[i];
		}
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			if (s[i] == -a[0])
			{
				printf("%d ", s[i] + a[1]);
			}
			else
			{
				printf("%d ", s[i] + a[0]);
			}
		}
		printf("\n");
	}
	return 0;
}

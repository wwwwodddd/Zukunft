#include <bits/stdc++.h>
using namespace std;
int n, z;
int a[2020], al, ar;
int b[2020], bl, br;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}
	sort(a, a + n);
	sort(b, b + n);
	ar = br = n - 1;
	while (al <= ar)
	{
		if (a[ar] > b[br])
		{
			z++;
			ar--;
			br--;
		}
		else if (a[al] > b[bl])
		{
			z++;
			al++;
			bl++;
		}
		else
		{
			if (a[al] < b[br])
			{
				z--;
			}
			al++;
			br--;
		}
	}
	printf("%d\n", z * 200);
	return 0;
}
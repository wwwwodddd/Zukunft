#include <bits/stdc++.h>
using namespace std;
int n, a[300020];
int LMSR()
{
	int i = 0, j = 1, k = 0;
	while (i < n && j < n && k < n)
	{
		if (a[(i + k) % n] == a[(j + k) % n])
		{
			k++;
		}
		else
		{
			if (a[(i + k) % n] < a[(j + k) % n])
			{
				j += k + 1;
			}
			else
			{
				i += k + 1;
			}
			if (i == j)
			{
				j++;
			}
			k = 0;
		}
	}
	return min(i, j);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int z = LMSR();
	for (int i = 0; i < n; i++)
	{
		printf("%d%c", a[(i + z) % n], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}

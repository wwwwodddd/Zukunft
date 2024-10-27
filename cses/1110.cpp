#include <bits/stdc++.h>
using namespace std;
int n;
char a[1000020];
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
	scanf("%s", a);
	n = strlen(a);
	int z = LMSR();
	for (int i = 0; i < n; i++)
	{
		printf("%c", a[(i + z) % n]);
	}
	return 0;
}
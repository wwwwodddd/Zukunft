#include <bits/stdc++.h>
using namespace std;
int n, x, s, z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		s += x;
		if (x == 0)
		{
			z += abs(s) + 1;
			s = 0;
		}
	}
	z += abs(s);
	printf("%d\n", z);
	return 0;
}
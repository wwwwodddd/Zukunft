#include <bits/stdc++.h>
using namespace std;
int s, f = 1, n;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		f *= i;
		s += f;
	}
	printf("%d\n", s);
	return 0;
}
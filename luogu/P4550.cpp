#include <bits/stdc++.h>
using namespace std;
int n;
double e, s, i;
int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		s += n / i;
		e += s * n / i;
	}
	printf("%.2f\n", e);
	return 0;
}
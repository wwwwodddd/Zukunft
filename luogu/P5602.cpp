#include <bits/stdc++.h>
using namespace std;
int n, a[300020];
double z, s;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = n; i--;)
	{
		s += a[i];
		z = max(z, s * s / (n - i));
	}
	printf("%.8f\n", z);
	return 0;
}
#include <cstdio>
int n;
long long x;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &x);
		printf("%lld\n", x);
	}
	return 0;
}
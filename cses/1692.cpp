#include <stdio.h>
int n, m, zc, ss, u;
int a[100020];
int s[1000020];
char z[1000020];
int main()
{
	scanf("%d", &n);
	m = 1 << (n - 1);
	s[ss++] = 0;
	zc = n + m * 2;
	for (; ss;)
	{
		u = s[--ss];
		z[--zc] = '0' + u % 2;
		u /= 2;
		for (; a[u] < 2;)
		{
			int w = 2 * u + a[u]++;
			s[ss++] = w;
			u = w % m;
		}
	}
	for (; zc;)
	{
		z[--zc] = '0';
	}
	z[m * 2 + n - 1] = 0;
	printf("%s\n", z);
	return 0;
}
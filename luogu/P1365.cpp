#include <bits/stdc++.h>
using namespace std;
int n;
char c;
double p, f, z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (c == 'o')
		{
			p = 1;
		}
		else if (c == 'x')
		{
			p = 0;
		}
		else
		{
			p = 0.5;
		}
		z += (2 * f + 1) * p;
		f = (f + 1) * p;
	}
	printf("%.4f\n", z);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
	scanf("%d%d%d", &a, &b, &c);
	if (a > b)
	{
		swap(a, b);
	}
	if (b > c)
	{
		swap(b, c);
	}
	if (a > b)
	{
		swap(a, b);
	}
	if (a + b <= c)
	{
		printf("Not triangle\n");
	}
	else
	{
		if (a * a + b * b < c * c)
		{
			printf("Obtuse triangle\n");
		}
		else if (a * a + b * b == c * c)
		{
			printf("Right triangle\n");
		}
		else
		{
			printf("Acute triangle\n");
		}
		if (a == b || b == c)
		{
			printf("Isosceles triangle\n");
		}
		if (a == c)
		{
			printf("Equilateral triangle\n");
		}
	}
	return 0;
}
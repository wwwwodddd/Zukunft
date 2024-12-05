#include <bits/stdc++.h>
using namespace std;
int b, c;
char a[20];
void F(int n)
{
	c = 0;
	for (; n > 0; n /= b)
	{
		if (n % b < 10)
		{
			a[c++] = n % b + '0';
		}
		else
		{
			a[c++] = n % b - 10 + 'A';
		}
	}
	reverse(a, a + c);
	a[c] = 0;
}
bool G()
{
	for (int i = 0; i < c; i++)
	{
		if (a[i] != a[c - 1 - i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d", &b);
	for (int i = 1; i <= 300; i++)
	{
		F(i * i);
		if (G())
		{
			F(i);
			printf("%s ", a);
			F(i * i);
			printf("%s\n", a);
		}
	}
}
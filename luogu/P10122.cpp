#include <bits/stdc++.h>
char s[9];
int a[9], p, q;
bool check(char a, char b, int i, int j, int k)
{
	if (s[i] != a && s[j] != a && s[k] != a)
	{
		return false;
	}
	if (s[i] != b && s[j] != b && s[k] != b)
	{
		return false;
	}
	if (s[i] != a && s[i] != b)
	{
		return false;
	}
	if (s[j] != a && s[j] != b)
	{
		return false;
	}
	if (s[k] != a && s[k] != b)
	{
		return false;
	}
	return true;
}
bool ok(char x, char y)
{
	if (check(x, y, 0, 3, 6))
	{
		return true;
	}
	if (check(x, y, 1, 4, 7))
	{
		return true;
	}
	if (check(x, y, 2, 5, 8))
	{
		return true;
	}
	if (check(x, y, 0, 1, 2))
	{
		return true;
	}
	if (check(x, y, 3, 4, 5))
	{
		return true;
	}
	if (check(x, y, 6, 7, 8))
	{
		return true;
	}
	if (check(x, y, 0, 4, 8))
	{
		return true;
	}
	if (check(x, y, 2, 4, 6))
	{
		return true;
	}
	return false;
}
int main()
{
	for (int i = 0; i < 9; i++)
	{
		scanf(" %c", &s[i]);
	}
	for (int i = 'A'; i <= 'Z'; i++)
	{
		if (ok(i, i))
		{
			p++;
		}
	}
	for (int i = 'A'; i <= 'Z'; i++)
	{
		for (int j = i + 1; j <= 'Z'; j++)
		{
			if (ok(i, j))
			{
				q++;
			}
		}
	}
	printf("%d\n%d\n", p, q);
	return 0;
}
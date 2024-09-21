#include <bits/stdc++.h>
using namespace std;
char s[200];
int a[200];
int b[200];
int n, l;
bool huiwen()
{
	for (int i = 0; i < l; i++)
	{
		if (a[i] != a[l - i - 1])
		{
			return false;
		}
	}
	return true;
}
void jia()
{
	memcpy(b, a, sizeof b);
	for (int i = 0; i < l; i++)
	{
		a[i] += b[l - i - 1];
		a[i + 1] += a[i] / n;
		a[i] %= n;
	}
	if (a[l])
	{
		l++;
	}
}
int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	l = strlen(s);
	for (int i = 0; i < l; i++)
	{
		if (isdigit(s[i]))
		{
			a[i] = s[i] - '0';
		}
		else
		{
			a[i] = s[i] - 'A' + 10;
		}
	}
	for (int i = 0; i <= 30; i++)
	{
		if (huiwen())
		{
			printf("STEP=%d\n", i);
			return 0;
		}
		jia();
	}
	printf("Impossible!\n");
	return 0;
}
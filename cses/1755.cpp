#include <bits/stdc++.h>
using namespace std;
int c[127], n, z;
char s[1000020];
int main()
{
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		c[s[i]]++;
	}
	for (int i = 0; i < 127; i++)
	{
		z += c[i] & 1;
	}
	if (z > 1)
	{
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	z = 0;
	for (int i = 0; i < 127; i++)
	{
		while (c[i] >= 2)
		{
			s[z] = s[n - z - 1] = i;
			z++;
			c[i] -= 2;
		}
		if (c[i] > 0)
		{
			s[n / 2] = i;
		}
	}
	printf("%s\n", s);
	return 0;
}
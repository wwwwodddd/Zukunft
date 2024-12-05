#include <bits/stdc++.h>
char s[300];
int b, g;
int main()
{
	scanf("%s", s);
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == 'b' || s[i + 1] == 'o' || s[i + 2] == 'y')
		{
			b++;
		}
		if (s[i] == 'g' || s[i + 1] == 'i' || s[i + 2] == 'r' || s[i + 3] == 'l')
		{
			g++;
		}
	}
	printf("%d\n%d\n", b, g);
	return 0;
}
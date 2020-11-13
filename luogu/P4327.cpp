#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	for (int i = 0; i <= s.size() * 4; i++)
	{
		printf(i % 4 == 2 ? i / 4 % 3 == 2 ? "*" : "#" : ".");
	}
	printf("\n");
	for (int i = 0; i <= s.size() * 4; i++)
	{
		printf(i % 2 == 1 ? i / 4 % 3 == 2 ? "*" : "#" : ".");
	}
	printf("\n");
	for (int i = 0; i <= s.size() * 4; i++)
	{
		if (i % 4 == 2)
		{
			putchar(s[i / 4]);
		}
		else if (i % 4 == 0)
		{
			if ((i > 0 && i < s.size() * 4 && i / 4 % 3 != 1) || (i == s.size() * 4 && s.size() % 3 == 0))
			{
				printf("*");
			}
			else
			{
				printf("#");
			}
		}
		else
		{
			printf(".");
		}
	}
	printf("\n");
	for (int i = 0; i <= s.size() * 4; i++)
	{
		printf(i % 2 == 1 ? i / 4 % 3 == 2 ? "*" : "#" : ".");
	}
	printf("\n");
	for (int i = 0; i <= s.size() * 4; i++)
	{
		printf(i % 4 == 2 ? i / 4 % 3 == 2 ? "*" : "#" : ".");
	}
	printf("\n");
	return 0;
}
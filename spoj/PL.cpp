#include <bits/stdc++.h>
using namespace std;
char s[100020];
int main()
{
	while (scanf("%s", s) != EOF)
	{
		int c[26] = {};
		for (int i = 0; s[i]; i++)
		{
			c[s[i] - 'a']++;
		}
		int s = 0;
		for (int i = 0; i < 26; i++)
		{
			s += c[i] % 2;
		}
		puts(s > 1 ? "-1" : "1");
	}
	return 0;
}
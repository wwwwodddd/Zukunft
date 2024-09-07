#include <bits/stdc++.h>
using namespace std;
int n;
char s[1000020];
int main()
{
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			s[i] = '0';
		}
		else
		{
			s[i] = '1';
		}
	}
	printf("%s\n", s);
	return 0;
}
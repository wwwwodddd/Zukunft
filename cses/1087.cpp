#include <bits/stdc++.h>
using namespace std;
char s[1000020];
char v[256];
int main()
{
	scanf("%s", s);
	for (int i = 0; s[i]; i++)
	{
		v[s[i]] = 1;
		if (v['A'] && v['C'] && v['G'] && v['T'])
		{
			printf("%c", s[i]);
			v['A'] = v['C'] = v['G'] = v['T'] = 0;
		}
	}
	if (v['A'] == 0)
	{
		printf("A\n");
	}
	else if (v['C'] == 0)
	{
		printf("C\n");
	}
	else if (v['G'] == 0)
	{
		printf("G\n");
	}
	else if (v['T'] == 0)
	{
		printf("T\n");
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, ac, bc;
char s[500020];
char t[500020];
int main()
{
	scanf("%d%s%s", &n, s, t);
	for (int i = 0; i < n; i++)
	{
		ac += s[i] == '0';
		bc += t[i] == '0';
		if (s[i] == '0' && t[i] == '0' && ac == bc)
		{
			ac--;
			bc--;
		}
	}
	printf("%d\n", ac == bc ? ac : -1);
	return 0;
}

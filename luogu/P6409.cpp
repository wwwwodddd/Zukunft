#include <bits/stdc++.h>
using namespace std;
int main()
{
	char c;
	while ((c = getchar()) != EOF)
	{
		putchar(c);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		{
			getchar();
			getchar();
		}
	}
	return 0;
}
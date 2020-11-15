#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
char c, s[11] = "helloworld";
int f[11];
int main()
{
	f[0] = 1;
	while (cin >> c)
	{
		c = tolower(c);
		for (int i = 9; i >= 0; i--)
		{
			if (c == s[i])
			{
				f[i + 1] = (f[i + 1] + f[i]) % mod;
			}
		}
	}
	printf("%d\n", f[10]);
	return 0;
}
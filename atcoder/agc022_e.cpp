#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
char s[300020];
int t[7][2] = {{1, 2}, {3, 0}, {4, 5}, {1, 1}, {6, 2}, {5, 5}, {4, 4}};
int f[300020][7];
int main()
{
	f[0][0] = 1;
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (s[i] != '1')
			{
				f[i + 1][t[j][0]] = (f[i + 1][t[j][0]] + f[i][j]) % p;
			}
			if (s[i] != '0')
			{
				f[i + 1][t[j][1]] = (f[i + 1][t[j][1]] + f[i][j]) % p;
			}
		}
	}
	printf("%d\n", (f[n][2] + f[n][5]) % p);
	return 0;
}
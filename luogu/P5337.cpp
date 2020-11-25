#include <bits/stdc++.h>
using namespace std;
int p = 1000000007;
char s[100020];
int a[26][26];
int b[26][26];
void mul(int a[26][26], int b[26][26])
{
	int w[26][26] = {};
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			for (int k = 0; k < 26; k++)
			{
				w[i][j] = (w[i][j] + (long long)a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, w, sizeof w);
}
int main() {
	long long n;
	scanf("%lld%s", &n, s);
	for (int i = 0; i < 26; i++)
	{
		a[i][i] = 1;
		for (int j = 0; j < 26; j++)
		{
			b[i][j] = 1;
		}
	}
	for (int i = 1; s[i]; i++)
	{
		b[s[i - 1] - 'a'][s[i] - 'a'] = 0;
	}
	for (n--; n > 0; n >>= 1)
	{
		if (n & 1)
		{
			mul(a, b);
		}
		mul(b, b);
	}
	int z = 0;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			z = (z + a[i][j]) % p;
		}
	}
	printf("%d\n", z);
	return 0;
}
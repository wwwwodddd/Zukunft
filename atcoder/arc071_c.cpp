#include <bits/stdc++.h>
using namespace std;
char s[100020];
char t[100020];
int n, m, q, a, b, c, d;
int main()
{
	scanf("%s%s%d", s + 1, t + 1, &q);
	for (int i = 1; s[i]; i++)
	{
		s[i] = (s[i - 1] + s[i] + 2) % 3;
	}
	for (int i = 1; t[i]; i++)
	{
		t[i] = (t[i - 1] + t[i] + 2) % 3;
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%s\n", (s[a - 1] - s[b] - t[c - 1] + t[d]) % 3 ? "NO" : "YES");
	}
	return 0;
}
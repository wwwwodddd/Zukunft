#include <bits/stdc++.h>
using namespace std;
int n, q, a, b;
char c[100020];
int f[100020];
int g[100020];
stack<char> s, t;
int main()
{
	scanf("%d%d%s", &n, &q, c + 1);
	for (int i = 1; i <= n; i++)
	{
		while (s.size() > 0 && s.top() > c[i])
		{
			s.pop();
		}
		f[i] = f[i - 1];
		if (s.size() == 0 || s.top() != c[i])
		{
			f[i]++;
			s.push(c[i]);
		}
	}
	for (int i = n; i >= 1; i--)
	{
		while (t.size() > 0 && t.top() > c[i])
		{
			t.pop();
		}
		g[i] = g[i + 1];
		if (t.size() == 0 || t.top() != c[i])
		{
			g[i]++;
			t.push(c[i]);
		}
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", f[a - 1] + g[b + 1]);
	}
	return 0;
}
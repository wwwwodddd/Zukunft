#include <bits/stdc++.h>
using namespace std;
stack<pair<int, int> > s;
int n, m, z;
int b[1020][1020];
void gao(int i)
{
	for (int j = 0; j <= m; j++)
	{
		int t = 0;
		while (s.size() && s.top().first >= b[i][j])
		{
			t += s.top().second;
			z = max(z, t * s.top().first);
			s.pop();
		}
		s.push(make_pair(b[i][j], t + 1));
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			scanf(" %c", &c);
			if (c == '.')
			{
				b[i][j] = b[i - 1][j] + 1;
			}
		}
		gao(i);
	}
	printf("%d\n", z);
	return 0;
}
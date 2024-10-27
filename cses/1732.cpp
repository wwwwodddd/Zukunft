#include <bits/stdc++.h>
using namespace std;
char t[1000020];
int p[1000020];
int main()
{
	scanf("%s", t + 1);
	int m = strlen(t + 1);
	int u = 0;
	for (int i = 2; i <= m; i++)
	{
		while (u > 0 && t[u + 1] != t[i])
		{
			u = p[u];
		}
		if (t[u + 1] == t[i])
		{
			u++;
		}
		p[i] = u;
	}
	vector<int> z;
	for (u = p[m]; u > 0; u = p[u])
	{
		z.push_back(u);
	}
	reverse(z.begin(), z.end());
	for (int i : z)
	{
		cout << i << " ";
	}
	return 0;
}
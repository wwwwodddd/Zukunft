#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int a, b;
ll f[20][110][110];
void update(ll &x, ll y)
{
	if (x < y)
	{
		x = y;
	}
}
int main()
{
	cin >> s >> a >> b;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j <= a; j++)
		{
			for (int k = 0; k <= b; k++)
			{
				if (k + (s[i] - '0' + 1) <= b)
				{
					update(f[i + 1][j][k + (s[i] - '0' + 1)], f[i][j][k] * 10 + 9);
				}
				for (int l = 0; l <= ('9' - s[i]); l++)
				{
					update(f[i + 1][j + l][k], f[i][j][k] * 10 + (s[i] - '0' + l));
				}
			}
		}
	}
	cout << f[s.size()][a][b] << endl;
	return 0;
}
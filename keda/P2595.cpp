#include <bits/stdc++.h>
using namespace std;
int t, n;
long long a[8], b[8];
set<vector<int> > s;
void gao()
{
	for (int k = 0; k < 8; k++)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 1; j < 8; j *= 2)
			{
				if (i & j)
				{
					if (b[j] != -1 && b[i] != -1 && b[i - j] != -1)
					{
						if (b[j] + b[i - j] != b[i])
						{
							return;
						}
					}
					if (b[j] != -1 && b[i] != -1 && b[i - j] == -1)
					{
						b[i - j] = b[i] - b[j];
					}
					if (b[j] != -1 && b[i] == -1 && b[i - j] != -1)
					{
						b[i] = b[j] + b[i - j];
					}
					if (b[j] == -1 && b[i] != -1 && b[i - j] != -1)
					{
						b[j] = b[i] - b[i - j];
					}
				}
			}
		}
	}
	if (1 <= b[1] && b[1] <= b[2] && b[2] <= b[4])
	{
		vector<int> c;
		c.push_back(b[1]);
		c.push_back(b[2]);
		c.push_back(b[4]);
		s.insert(c);
	}
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		s.clear();
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = n + 1; i <= 7; i++)
		{
			a[i] = -1;
		}
		sort(a + 1, a + 8);
		do
		{
			memcpy(b, a, sizeof b);
			gao();
		}
		while (next_permutation(a + 1, a + 8));
		printf("%lu\n", s.size());
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int h1, h2, w1, w2;
int a[20][20];
int b[20][20];
int main()
{
	cin >> h1 >> w1;
	for (int i = 0; i < h1; i++)
	{
		for (int j = 0; j < w1; j++)
		{
			cin >> a[i][j];
		}
	}
	cin >> h2 >> w2;
	for (int i = 0; i < h2; i++)
	{
		for (int j = 0; j < w2; j++)
		{
			cin >> b[i][j];
		}
	}
	for (int k = 0; k < 1 << h1; k++)
	{
		if (__builtin_popcount(k) == h2)
		{
			for (int l = 0; l < 1 << w1; l++)
			{
				if (__builtin_popcount(l) == w2)
				{
					vector<int> r, c;
					for (int i = 0; i < h1; i++)
					{
						if (k >> i & 1)
						{
							r.push_back(i);
						}
					}
					for (int i = 0; i < w1; i++)
					{
						if (l >> i & 1)
						{
							c.push_back(i);
						}
					}
					assert(r.size() == h2);
					assert(c.size() == w2);
					int f = 1;
					for (int i = 0; i < h2 && f; i++)
					{
						for (int j = 0; j < w2 && f; j++)
						{
							if (b[i][j] != a[r[i]][c[j]])
							{
								f = 0;
							}
						}
					}
					if (f)
					{
						cout << "Yes" << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int h1, h2, w1, w2;
int a[20][20];
int b[20][20];
int r[20];
int c[20];
void dfsc(int x, int y)
{
	if (y > w2 || y + w1 - x < w2)
	{
		return;
	}
	if (x == w1)
	{
		int f = 1;
		for (int i = 0; i < h2; i++)
		{
			for (int j = 0; j < w2; j++)
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
			exit(0);
		}
		return;
	}
	dfsc(x + 1, y);
	c[y] = x;
	dfsc(x + 1, y + 1);
}
void dfsr(int x, int y)
{
	if (y > h2 || y + h1 - x < h2)
	{
		return;
	}
	if (x == h1)
	{
		dfsc(0, 0);
		return;
	}
	dfsr(x + 1, y);
	r[y] = x;
	dfsr(x + 1, y + 1);
}
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
	dfsr(0, 0);
	cout << "No" << endl;
	return 0;
}

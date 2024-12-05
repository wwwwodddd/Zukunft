#include <bits/stdc++.h>
using namespace std;
int n;
long long c, z;
int r[2520][2520];
pair<int, int> a[2520];
void gao()
{
	memset(r, 0, sizeof r);
	for (int j = n - 1; j >= 0; j--)
	{
		c = 1;
		for (int i = j - 1; i >= 0; i--)
		{
			if (a[j].second > a[i].second)
			{
				r[i][j] = c;
			}
			else
			{
				c++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		c = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j].second > a[i].second)
			{
				z += c * r[i][j];
			}
			else
			{
				c++;
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	z = n + 1;
	gao();
	for (int i = 0; i < n; i++)
	{
		a[i].second = -a[i].second;
	}
	gao();
	cout << z << endl;
	return 0;
}
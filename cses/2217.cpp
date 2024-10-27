#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z = 1;
int a[200020];
int p[200020];
void update(int i, int x)
{
	if (p[i] < p[i - 1])
	{
		z--;
	}
	if (p[i + 1] < p[i])
	{
		z--;
	}
	p[i] = x;
	if (p[i] < p[i - 1])
	{
		z++;
	}
	if (p[i + 1] < p[i])
	{
		z++;
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		p[a[i]] = i;
	}
	for (int i = 2; i <= n; i++)
	{
		if (p[i] < p[i - 1])
		{
			z++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		swap(a[x], a[y]);
		update(a[x], x);
		update(a[y], y);
		cout << z << endl;
	}
	return 0;
}

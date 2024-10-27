#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int f[100020];
vector<int> z;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		f[F(x)] = F(y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (F(i) != F(1))
		{
			z.push_back(i);
			f[F(i)] = F(1);
		}
	}
	cout << z.size() << endl;
	for (int i : z)
	{
		cout << 1 << " " << i << endl;
	}
	return 0;
}
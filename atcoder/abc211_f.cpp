#include <bits/stdc++.h>
using namespace std;
int n, m, q, x, y;
vector<pair<pair<int, int>, int> > a;
pair<int, int> b[100020];
int c[100020];
vector<int> z;
void change(int x, int y)
{
	for (x++; x < 100010; x += x & -x)
	{
		c[x] += y;
	}
}
int query(int x)
{
	int re = 0;
	for (x++; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		long long s = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> b[j].first >> b[j].second;
		}
		b[m] = b[0];
		for (int j = 1; j <= m; j++)
		{
			s += (long long)b[j - 1].first * b[j].second - (long long)b[j].first * b[j - 1].second;
		}
		if (s < 0)
		{
			reverse(b, b + m);
		}
		for (int i = 0; i < m; i++)
		{
			if (i & 1)
			{
				a.push_back(make_pair(b[i], +1));
			}
			else
			{
				a.push_back(make_pair(b[i], -1));
			}
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> x >> y;
		a.push_back(make_pair(make_pair(x, y), 2 + i));
	}
	sort(a.begin(), a.end());
	z.resize(q);
	for (pair<pair<int, int>, int> i : a)
	{
		if (i.second >= 2)
		{
			z[i.second - 2] = query(i.first.second);
		}
		else
		{
			change(i.first.second, i.second);
		}
	}
	for (int i = 0; i < z.size(); i++)
	{
		cout << z[i] << endl;
	}
	return 0;
}
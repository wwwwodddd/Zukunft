#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> v, h;
vector<int> vs, hs;
void zou0(int &x, int &y, int &d, int &t)
{
	int px = lower_bound(v.begin(), v.end(), x) - v.begin();
	int py = lower_bound(h.begin(), h.end(), y) - h.begin();
	bool onv = px < v.size() && v[px] == x;
	bool onh = py < h.size() && h[py] == y;
	assert(onv || onh);
	if (!onh || (t % 2 == 0 && onv)) // north
	{
		int dest = 2e9;
		if (onh)
		{
			py++;
		}
		if (py < h.size())
		{
			dest = h[py];
		}
		int dd = min(dest - y, d);
		d -= dd;
		t += dd;
		y += dd;
	}
	else // east
	{
		int dest = 2e9;
		if (onv)
		{
			px++;
		}
		if (px < v.size())
		{
			dest = v[px];
		}
		int dd = min(dest - x, d);
		d -= dd;
		t += dd;
		x += dd;
	}
	// cout << "zou0 " << x << " " << y << " " << d << " " << t << endl;
}
void zou(int &x, int &y, int &d, int &t)
{
	if (d == 0)
	{
		return;
	}
	int px = upper_bound(vs.begin(), vs.end(), x) - vs.begin();
	int py = upper_bound(hs.begin(), hs.end(), y) - hs.begin();
	if (t % 2 == 0) // north
	{
		int dest = 2e9;
		if (py < hs.size())
		{
			dest = hs[py];
		}
		int dd = min(dest - y, d);
		d -= dd;
		t += dd;
		y += dd;
	}
	else // east
	{
		int dest = 2e9;
		if (px < vs.size())
		{
			dest = vs[px];
		}
		int dd = min(dest - x, d);
		d -= dd;
		t += dd;
		x += dd;
	}
}
pair<int, int> zuo(int x, int y, int d)
{
	int t = 0;
	zou0(x, y, d, t);
	zou(x, y, d, t);
	zou(x, y, d, t);
	if (d > 0)
	{
		int px = lower_bound(vs.begin(), vs.end(), x) - vs.begin();
		int py = lower_bound(hs.begin(), hs.end(), y) - hs.begin();
		assert(vs[px] == x);
		assert(hs[py] == y);
		for (int i = 20; i >= 0; i--)
		{
			if (px + (1 << i) < vs.size() && py + (1 << i) < hs.size())
			{
				int dx = vs[px + (1 << i)] - vs[px];
				int dy = hs[py + (1 << i)] - hs[py];
				if (d >= dx + dy)
				{
					d -= dx + dy;
					t += dx + dy;
					px += 1 << i;
					py += 1 << i;
				}
			}
		}
		x = vs[px];
		y = hs[py];
		zou(x, y, d, t);
		zou(x, y, d, t);
	}
	assert(d == 0);
	return make_pair(x, y);
}
pair<int, int> bf(int x, int y, int d)
{
	int t = 0;
	while (d > 0)
	{
		zou0(x, y, d, t);
	}
	return make_pair(x, y);
}
int main()
{
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		char o;
		int x;
		cin >> o >> x;
		if (o == 'V')
		{
			v.push_back(x);
		}
		else
		{
			h.push_back(x);
		}
	}
	sort(v.begin(), v.end());
	sort(h.begin(), h.end());
	for (int i : v)
	{
		if (vs.size() > 0 && vs.back() % 2 == i % 2)
		{
			continue;
		}
		vs.push_back(i);
	}
	for (int i : h)
	{
		if (hs.size() > 0 && hs.back() % 2 == i % 2)
		{
			continue;
		}
		hs.push_back(i);
	}
	for (int i = 0; i < q; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		pair<int, int> z0 = zuo(x, y, d);
		// pair<int, int> z1 = bf(x, y, d);
		cout << z0.first << " " << z0.second << endl;
		// if (z0 != z1)
		// {
		//     cout << "z1 " << z1.first << " " << z1.second << endl;
		//     assert(false);
		// }
	}
	return 0;
}
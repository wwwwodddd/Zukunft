#include <bits/stdc++.h>
using namespace std;
pair<int, int> zuo(int x, int y)
{
	cout << x << " " << y << endl;
	fflush(stdout);
	cin >> x >> y;
	return {x, y};
}
int n, l, r;
int f[2020];
int v[2020];
vector<pair<int, int> > s;
void erase(int x, int y)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].first <= x && x < s[i].first + s[i].second)
		{
			assert(x + y <= s[i].first + s[i].second);
			if (x - s[i].first > 0)
			{
				s.push_back({s[i].first, x - s[i].first});
			}
			if (s[i].first + s[i].second - (x + y) > 0)
			{
				s.push_back({x + y, s[i].first + s[i].second - (x + y)});
			}
			s.erase(s.begin() + i);
			return;
		}
	}
}
pair<int, int> find()
{
	int sg = 0;
	for (int i = 0; i < s.size(); i++)
	{
		sg ^= f[s[i].second];
	}
	assert(sg > 0);
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = l; j <= s[i].second; j++)
		{
			if ((sg ^ f[s[i].second] ^ f[j - l] ^ f[s[i].second - j]) == 0)
			{
				return {s[i].first + j - l, l};
			}
		}
	}
	assert(false);
}
int main()
{
	cin >> n >> l >> r;
	if (l < r)
	{
		cout << "First" << endl;
		fflush(stdout);
		int c = l;
		if (c % 2 != n % 2)
		{
			c++;
		}
		int d = (n - c) / 2;
		pair<int, int> u = zuo(d + 1, c);
		while (u.first && u.second)
		{
			if (u.first <= d)
			{
				u.first += d + c;
			}
			else
			{
				u.first -= d + c;
			}
			u = zuo(u.first, u.second);
		}
		assert(u.first == 0 && u.second == 0);
	}
	else // l == r
	{
		for (int i = l; i <= n; i++)
		{
			for (int j = l; j <= i; j++)
			{
				v[f[j - l] ^ f[i - j]] = i;
			}
			while (v[f[i]] == i)
			{
				f[i]++;
			}
		}
		s.push_back({1, n});
		if (f[n] == 0)
		{
			cout << "Second" << endl;
			fflush(stdout);
			int a, b;
			cin >> a >> b;
			erase(a, b);
		}
		else
		{
			cout << "First" << endl;
			fflush(stdout);
		}
		while (true)
		{
			pair<int, int> v = find();
			erase(v.first, v.second);
			pair<int, int> u = zuo(v.first, v.second);
			if (u.first && u.second)
			{
				erase(u.first, u.second);
			}
			else
			{
				assert(u.first == 0 && u.second == 0);
				break;
			}
		}
	}
	return 0;
}

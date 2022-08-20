#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll b, k, sx, sy, gx, gy;
ll dist(ll sx, ll sy, ll gx, ll gy)
{
	if (sx % b == 0 && gx % b == 0 && sx != gx && sy / b == gy / b)
	{
		return abs(sx - gx) + min(sy % b + gy % b, 2 * b - sy % b - gy % b);
	}
	if (sy % b == 0 && gy % b == 0 && sy != gy && sx / b == gx / b)
	{
		return abs(sy - gy) + min(sx % b + gx % b, 2 * b - sx % b - gx % b);
	}
	return abs(sx - gx) + abs(sy - gy);
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> b >> k >> sx >> sy >> gx >> gy;
		ll z = (abs(sx - gx) + abs(sy - gy)) * k;
		vector<array<ll, 3> > s, g;
		s.push_back({sx / b * b, sy, sx % b});
		s.push_back({sx / b * b + b, sy, b - sx % b});
		s.push_back({sx, sy / b * b, sy % b});
		s.push_back({sx, sy / b * b + b, b - sy % b});
		g.push_back({gx / b * b, gy, gx % b});
		g.push_back({gx / b * b + b, gy, b - gx % b});
		g.push_back({gx, gy / b * b, gy % b});
		g.push_back({gx, gy / b * b + b, b - gy % b});
		for (auto i : s)
		{
			for (auto j : g)
			{
				z = min(z, dist(i[0], i[1], j[0], j[1]) + (i[2] + j[2]) * k);
			}
		}
		cout << z << endl;
	}
	return 0;
}

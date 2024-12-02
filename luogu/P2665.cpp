#include <bits/stdc++.h>
using namespace std;
int n, x[220], y[220];
int main()
{
	set<pair<int, int> > s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		for (int j = 0; j < i; j++)
		{
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			if (dx < 0 || dx == 0 && dy < 0)
			{
				dx = -dx;
				dy = -dy;
			}
			int g = __gcd(dx, dy);
			dx /= g;
			dy /= g;
			s.emplace(dx, dy);
		}
	}
	cout << s.size() << endl;
	return 0;
}
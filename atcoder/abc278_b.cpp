#include <bits/stdc++.h>
using namespace std;
bool ok(int h, int m)
{
	int x = h / 10 * 10 + m / 10;
	int y = h % 10 * 10 + m % 10;
	return x < 24 && y < 60;
}
int main()
{
	int h, m;
	cin >> h >> m;
	while (!ok(h, m))
	{
		m++;
		if (m == 60)
		{
			m = 0;
			h++;
		}
		if (h == 24)
		{
			h = 0;
		}
	}
	cout << h << " " << m << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, x, y, dx = 1, dy = 0;
string s;
int main()
{
	cin >> n >> s;
	for (char c: s)
	{
		if (c == 'S')
		{
			x += dx;
			y += dy;
		}
		else
		{
			int tx = dx;
			int ty = dy;
			dy = -tx;
			dx = ty;
		}
	}
	cout << x << ' ' << y << endl;
	return 0;
}

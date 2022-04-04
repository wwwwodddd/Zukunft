#include <bits/stdc++.h>
using namespace std;
double x, y, d;
int main()
{
	cin >> x >> y;
	d = hypot(x, y);
	x /= d;
	y /= d;
	cout << fixed << setprecision(9) << x << " " << y << endl;
	return 0;
}

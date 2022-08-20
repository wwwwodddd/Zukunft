#include <bits/stdc++.h>
using namespace std;
double x, y, d;
int main()
{
	cin >> x >> y >> d;
	d = d / 180 * acos(-1.);
	cout << fixed << setprecision(9) << x * cos(d) - y * sin(d) << " " << x * sin(d) + y * cos(d) << endl;
	return 0;
}

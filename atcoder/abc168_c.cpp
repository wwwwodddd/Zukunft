#include <bits/stdc++.h>
using namespace std;
double a, b, h, m, pi = acos(-1.);
int main()
{
	cin >> a >> b >> h >> m;
	double ra = (h * 30 + m * 0.5) / 180 * pi;
	double xa = a * cos(ra);
	double ya = a * sin(ra);
	double rb = (m * 6) / 180 * pi; 
	double xb = b * cos(rb);
	double yb = b * sin(rb);
	cout << fixed << setprecision(12) << hypot(xa - xb, ya - yb) << endl;
	return 0;
}

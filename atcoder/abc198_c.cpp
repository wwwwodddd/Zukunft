#include <bits/stdc++.h>
using namespace std;
double r, x, y;
int main()
{
	cin >> r >> x >> y;
	double d = hypot(x, y);
	cout << (d < r ? 2 : ceil(d / r)) << endl;
	return 0;
}

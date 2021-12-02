#include <bits/stdc++.h>
using namespace std;
double sx, sy, gx, gy;
int main()
{
	cin >> sx >> sy >> gx >> gy;
	cout << fixed << setprecision(9) << (sy * gx + sx * gy) / (sy + gy) << endl;
	return 0;
}

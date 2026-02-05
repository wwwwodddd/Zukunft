#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	x1 -= x3;
	y1 -= y3;
	x2 -= x3;
	y2 -= y3;
	cout << abs(x1 * y2 - x2 * y1) / 2 << endl;
	return 0;
}
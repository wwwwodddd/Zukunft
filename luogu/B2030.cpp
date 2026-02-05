#include <bits/stdc++.h>
using namespace std;
double xa, ya, xb, yb;
int main()
{
	cin >> xa >> ya >> xb >> yb;
	cout << fixed << setprecision(3) << hypot(xb - xa, yb - ya) << endl;
	return 0;
}
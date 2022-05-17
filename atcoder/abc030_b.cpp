#include <bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
	cin >> n >> m;
	n %= 12;
	double z = abs(n * 30 - m * 5.5);
	cout << fixed << setprecision(6) << min(z, 360 - z) << endl;
	return 0;
}

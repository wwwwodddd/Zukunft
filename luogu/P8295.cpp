#include <bits/stdc++.h>
using namespace std;
double x, y, z;
int n;
int main()
{
	cin >> x >> y >> n;
	z = 1000 / y * x;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		z = min(z, 1000 / y * x);
	}
	cout << fixed << setprecision(2) << z << endl;
	return 0;
}

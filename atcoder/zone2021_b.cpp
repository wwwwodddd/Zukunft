#include <bits/stdc++.h>
using namespace std;
int n;
double D, H, di, hi, z;
int main()
{
	cin >> n >> D >> H;
	for (int i = 0; i < n; i++)
	{
		cin >> di >> hi;
		z = max(z, (hi * D - di * H) / (D - di));
	}
	cout << fixed << setprecision(9) << z << endl;
	return 0;
}

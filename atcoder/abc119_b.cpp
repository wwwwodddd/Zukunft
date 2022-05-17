#include <bits/stdc++.h>
using namespace std;
int n;
double x, s;
string y;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (y == "BTC")
		{
			x *= 380000;
		}
		s += x;
	}
	cout << fixed << setprecision(6) << s << endl;
	return 0;
}

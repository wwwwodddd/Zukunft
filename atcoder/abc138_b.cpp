#include <bits/stdc++.h>
using namespace std;
int n;
double s, x;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += 1 / x;
	}
	cout << fixed << setprecision(6) << (1 / s) << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, c;
int a[9];
int x[9];
int y[9];
double s;
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		a[i] = i;
	}
	do
	{
		for (int i = 1; i < n; i++)
		{
			s += hypot(x[a[i]] - x[a[i - 1]], y[a[i]] - y[a[i - 1]]);
		}
		c++;
	}
	while (next_permutation(a, a + n));
	cout << fixed << setprecision(10) << s / c << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, z;
int x[100];
int y[100];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			z = max(z, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
		}
	}
	cout << fixed << setprecision(9) << sqrt(z) << endl;
	return 0;
}

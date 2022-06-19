#include <bits/stdc++.h>
using namespace std;
int n;
double s, z;
double a[100020];
double b[100020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		s += a[i] / b[i];
	}
	s /= 2;
	for (int i = 0; i < n; i++)
	{
		if (s > a[i] / b[i])
		{
			s -= a[i] / b[i];
			z += a[i];
		}
		else
		{
			cout << fixed << setprecision(9) << z + s * b[i] << endl;
			break;
		}
	}
	return 0;
}

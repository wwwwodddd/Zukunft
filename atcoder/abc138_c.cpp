#include <bits/stdc++.h>
using namespace std;
int n, a[50];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	double s = a[0];
	for (int i = 1; i < n; i++)
	{
		s = (s + a[i]) / 2;
	}
	cout << s << endl;
	return 0;
}

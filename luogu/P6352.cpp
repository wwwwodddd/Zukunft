#include <bits/stdc++.h>
using namespace std;
int a[3];
int main()
{
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	if (2 * a[1] == a[0] + a[2])
	{
		cout << 2 * a[2] - a[1] << endl;
	}
	else
	{
		cout << a[0] + a[2] - a[1] << endl;
	}
	return 0;
}
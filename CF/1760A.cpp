#include <bits/stdc++.h>
using namespace std;
int t, a[3];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		cout << a[1] << endl;
	}
	return 0;
}

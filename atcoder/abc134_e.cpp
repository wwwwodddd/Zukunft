#include <bits/stdc++.h>
using namespace std;
int n, x, f[100000];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		*upper_bound(f, f + n, ~x) = ~x;
	}
	cout << lower_bound(f, f + n, 0) - f << endl;
	return 0;
}

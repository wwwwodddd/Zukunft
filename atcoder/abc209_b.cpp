#include <bits/stdc++.h>
using namespace std;
int n, x, a;
int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		x -= a - (i & 1);
	}
	cout << (x < 0 ? "No" : "Yes") << endl;
	return 0;
}

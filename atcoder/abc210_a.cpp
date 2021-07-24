#include <bits/stdc++.h>
using namespace std;
int n, a, x, y;
int main()
{
	cin >> n >> a >> x >> y;
	cout << min(n * x, a * x + (n - a) * y) << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, m, x, t, d;
int main()
{
	cin >> n >> m >> x >> t >> d;
	cout << t - max(x - m, 0) * d << endl;
	return 0;
}

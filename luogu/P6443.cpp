#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main()
{
	cin >> m >> n >> k;
	cout << min((m + n - k) / 3, min(m / 2, n)) << endl;
	return 0;
}
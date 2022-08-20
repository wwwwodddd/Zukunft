#include <bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
	cin >> n >> m;
	cout << max(8 * n + 3 * m - 28, 0) << endl;
	return 0;
}

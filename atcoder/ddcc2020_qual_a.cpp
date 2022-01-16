#include <bits/stdc++.h>
using namespace std;
int x, y;
int main()
{
	cin >> x >> y;
	cout << (max(4 - x, 0) + max(4 - y, 0) + (x == 1 && y == 1) * 4) * 100000 << endl;
	return 0;
}

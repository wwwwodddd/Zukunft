#include <bits/stdc++.h>
using namespace std;
int x, y;
int main()
{
	cin >> x >> y;
	cout << max((y - x + 9) / 10, 0) << endl;
	return 0;
}

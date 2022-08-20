#include <bits/stdc++.h>
using namespace std;
int w, h, x, y;
int main()
{
	cin >> w >> h >> x >> y;
	cout << .5 * w * h << " " << (x * 2 == w && y * 2 == h) << endl;
	return 0;
}

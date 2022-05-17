#include <bits/stdc++.h>
using namespace std;
int h, w, n;
int main()
{
	cin >> h >> w >> n;
	cout << (n - 1) / max(h, w) + 1 << endl;
	return 0;
}

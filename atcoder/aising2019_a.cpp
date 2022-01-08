#include <bits/stdc++.h>
using namespace std;
int n, h, w;
int main()
{
	cin >> n >> h >> w;
	cout << (n - h + 1) * (n - w + 1) << endl;
	return 0;
}

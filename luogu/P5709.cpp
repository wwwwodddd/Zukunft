#include <bits/stdc++.h>
using namespace std;
int m, t, s;
int main()
{
	cin >> m >> t >> s;
	cout << max(t ? m - (s + t - 1) / t : 0, 0) << endl;
	return 0;
}
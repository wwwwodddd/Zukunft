#include <bits/stdc++.h>
using namespace std;
int n, k;
int main()
{
	cin >> n >> k;
	cout << (k == 1 ? 0 : n - k) << endl;
	return 0;
}

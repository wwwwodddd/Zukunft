#include <bits/stdc++.h>
using namespace std;
int t;
long long l, r;
int main() {
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		cin >> l >> r;
		cout << ((l+r) % 9 * (r-l+1) % 9 * 5 % 9) << endl;
//		cout << ((l+r) % 18 * (r-l+1) % 18 / 2) << endl;
	}
}
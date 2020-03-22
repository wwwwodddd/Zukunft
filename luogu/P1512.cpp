#include<bits/stdc++.h>
using namespace std;
int t, a, b, c;
int main() {
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		cin >> a >> b >> c;
		if (b == 9 && c == 30 || b == 11 && c == 30 || (b + c) % 2 == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
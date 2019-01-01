#include <bits/stdc++.h>
using namespace std;
int n, k;
int F(int x) {
	if (x - k > 0 && (x - k) % 2 == 0) {
		return F((x + k) / 2) + F((x - k) / 2);
	} else {
		return 1;
	}
}
int main() {
	cin >> n >> k;
	cout << F(n) << endl;
	return 0;
}
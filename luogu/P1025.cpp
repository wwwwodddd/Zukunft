#include <bits/stdc++.h>
using namespace std;
int F(int x, int y) {
	if (x == y) {
		return 1;
	}
	if (x < y || y == 0) {
		return 0;
	}
	return F(x - 1, y - 1) + F(x - y, y);
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << F(n, k) << endl;
	return 0;
}

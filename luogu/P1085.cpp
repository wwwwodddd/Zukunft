#include <bits/stdc++.h>
using namespace std;
int a, b, x, y;
int main() {
	for (int i = 0; i < 7; i++) {
		cin >> x >> y;
		if (x + y > 8 && x + y > b) {
			b = x + y;
			a = i + 1;
		}
	}
	cout << a << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, x, f, g;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 1) {
			g = min(g + 1, f);
		} else {
			f += 1;
		}
	}
	cout << g << endl;
}
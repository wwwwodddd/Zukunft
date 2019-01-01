#include <bits/stdc++.h>
using namespace std;
int k, t;
int main() {
	cin >> k;
	for (int i = 10000; i <= 30000; i++) {
		if (i % 1000 % k == 0 && i / 10 % 1000 % k == 0 && i / 100 % 1000 % k == 0) {
			cout << i << endl;
			t = 1;
		}
	}
	if (t == 0) {
		cout << "No" << endl;
	}
	return 0;
}

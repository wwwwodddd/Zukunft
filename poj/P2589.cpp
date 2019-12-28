#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	string a[2], b[2];
	cin >> a[0] >> a[1];

	for (int i = 0; i < 1000; i++) {
		b[0] = a[0][0] + b[0];
		b[1] = a[1][0] + b[1];
		if (a[0][0] == a[1][0]) {
			int t = rand() / 99 % 2;
			b[t] = b[1 - t] + b[t];
			b[1 - t] = "";
			cout << "Snap! for " << (t ? "John" : "Jane") << ": " << b[t] << endl;
		}
		for (int j = 0; j < 2; j++) {
			a[j].erase(0, 1);
			if (a[j].size() == 0) {
				a[j] = b[j];
				if (a[j].size() == 0) {
					cout << (j ? "Jane" : "John") << " wins." << endl;
					return 0;
				}
				reverse(a[j].begin(), a[j].end());
				b[j] = "";
			}
		}
	}
	cout << "Keeps going and going ..." << endl;
	return 0;
}
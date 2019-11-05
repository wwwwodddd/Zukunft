#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string conv(int x) {
	string s = "";
	while (x) {
		s = (char)('0' + x % 10) + s;
		x /= 10;
	}
	return s;
}
int a[20];
int main() {
	string ans = "0000000000000000";
	for (int i = 0; i < 10; i++) {
		a[i] = i + 1;
	}
	do {
		int s[5] = {};
		for (int i = 0; i < 5; i++) {
			s[i] = a[2 * i] + a[2 * i + 1] + a[(2 * i + 3) % 10];
		}
		bool same = true;
		for (int i = 1; i < 5; i++) {
			if (s[i - 1] != s[i]) {
				same = false;
			}
		}
		for (int i = 0; i < 5; i++) {
			if (a[2 * i + 1] == 10) {
				same = false;
			}
		}
		if (!same) {
			continue;
		}
		int start = 0;
		for (int i = 0; i < 5; i++) {
			if (a[2 * i] < a[2 * start]) {
				start = i;
			}
		}
		string tmp = "";
		for (int i = 0; i < 5; i++) {
			tmp += conv(a[2 * (start + i) % 10]);
			tmp += conv(a[(2 * (start + i) + 1) % 10]);
			tmp += conv(a[(2 * (start + i) + 3) % 10]);
		}
		if (ans < tmp) {
			ans = tmp;
		}
	} while(next_permutation(a, a + 10));
	cout << ans << endl;
	return 0;
}
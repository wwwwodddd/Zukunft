#include <bits/stdc++.h>
using namespace std;
string s, a[] = {"", "red", "yellow", "green", "brown", "blue", "pink", "black"};
int c[10], ans, n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			if (a[j] == s) {
				c[j]++;
				ans += j;
			}
		}
	}
	if (c[1] == n) {
		printf("%d\n", 1);
	} else {
		int big = 0;
		for (int i = 0; i < 8; i++) {
			if (c[i] > 0) {
				big = i;
			}
		}
		ans += c[1] * big;
		cout << ans << endl;
	}
	return 0;
}
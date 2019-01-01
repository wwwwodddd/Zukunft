#include <bits/stdc++.h>
using namespace std;
int x, n, s;
int main() {
	cin >> x >> n;
	while (n % 7 != 0) {
		if ((++x) % 7 > 1) {
			s += 250;
		}
		n--;
	}
	cout << s + n / 7 * 1250 << endl;
	return 0;
}

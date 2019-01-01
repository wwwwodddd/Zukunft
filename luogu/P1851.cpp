#include <bits/stdc++.h>
using namespace std;
int F(int x) {
	int s = -x;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			s += i;
			if (i * i < x) {
				s += x / i;
			}
		}
	}
	return s;
}

int main() {
	int s;
	cin >> s;
	for (;; s++) {
		int t = F(s);
		if (s != t && s == F(t)) {
			break;
		}
	}
	printf("%d %d\n", s, F(s));
	return 0;
}
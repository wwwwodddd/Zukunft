#include <bits/stdc++.h>
using namespace std;
long long A, L, R;
int Q;
int a[100], ac;
int b[100], bc;
long long F(long long B) {
	long long re = 0;
	long long t = 1;
	bc = 0;
	memset(b, 0, sizeof b);
	while (B > 0) {
		b[bc++] = B % 10;
		B /= 10;
	}
	int DIGITS = 18;
	for (int i = 0; i < DIGITS; i++) {
		t *= 10 - a[i];
	}
	for (int i = DIGITS; i >= 0; i--) {
		for (int j = 0; j < b[i]; j++) {
			if (j + a[i] < 10) {
				re += t;
			} else if (j + a[i] >= 10) {
				return re;
			}
		}
		if (a[i] + b[i] >= 10) {
			return re;
		}
		if (i > 0) {
			t /= 10 - a[i - 1];
		}
	}
	return re;
}
int main() {
	cin >> A >> Q;
	while (A > 0) {
		a[ac++] = A % 10;
		A /= 10;
	}
	for (int qq = 0; qq < Q; qq++) {
		cin >> L >> R;
		cout << F(R + 1) - F(L) << endl;
	}
	return 0;
}
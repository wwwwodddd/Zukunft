#include <bits/stdc++.h>
using namespace std;
int f[1000020];
int c[1000020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int U(int x, int y) {
	x = F(x);
	y = F(y);
	if (x != y) {
		c[y] += c[x];
		f[x] = y;
	}
}
int p = 1000000;
long long s[100];
int main() {
	for (int i = 1; i <= 55; i++) {
		s[i] = (100003LL - 200003LL * i + 300007LL * i * i * i) % p;
	}
	for (int i = 0; i < p; i++) {
		f[i] = i;
		c[i] = 1;
	}
	int cnt = 0;
	for (int i = 1;; i++) {
		if (i > 55) {
			s[i % 100] = (s[(i + 100 - 24) % 100] + s[(i + 100 - 55) % 100]) % p;
		}
		if (i % 2 == 0) {
			if (s[i % 100] != s[(i - 1) % 100]) {
				cnt++;
				U(s[i % 100], s[(i - 1) % 100]);
			}
			if (c[F(524287)] >= 990000) {
				cerr << cnt << endl;
				break;
			}
			
		}
	}

	
	return 0;
}

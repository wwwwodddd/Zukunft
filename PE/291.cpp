#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long mul(long long x, long long y, long long p) {
	long long w = x * y - (long long)(((long double)x * y) / p) * p;
	while (w >= p) {
		w -= p;
	}
	while (w < 0) {
		w += p;
	}
	return w;
}

long long pow(long long x, long long y, long long p) {
	long long re = 1;
	for (; y; y >>= 1) {
		if (y & 1) {
			re = mul(re, x, p);
		}
		x = mul(x, x, p);
	}
	return re;
}


bool test(int pr, long long s) {
	if (s % pr == 0) {
		return true;
	}
	long long t = s - 1, b = 0;
	while (t % 2 == 0) {
		t /= 2;
		b++;
	}
	long long w = pow(pr, t, s);
	if (w == 1) {
		return true;
	}
	bool flag = false;
	for (int i = 0; i < b; i++) {
		if (w == s - 1) {
			flag = true;
		}
		w = mul(w, w, s);
	}
	return flag;
}
bool prime(long long s) {
	if (s < 2) {
		return false;
	}
	int wocao[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
	for (int i = 0; i < 13; i++) {
		if (s % wocao[i] == 0) {
			if (s == wocao[i]) {
				return true;
			} else {
				return false;
			}
		}
	}

	for (int i = 0; i < 13; i++) {
		if (!test(wocao[i], s)) {
			return false;
		}
	}
	return true;
}

int main() {

	int cnt = 0;
	for (long long i = 1; i <= 100000000; i++) {
		if (i % 1000000 == 0) {
			printf("%lld %d\n", i, cnt);
		}
		long long s = i * i + (i + 1) * (i + 1);
		if (s >= 5000000000000000LL) {
			break;
		}
		if (prime(s)) {
			cnt += 1;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
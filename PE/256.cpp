#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;
int x;
int check(int y, int p, int q) {
	int sn = y / p;
	int sy = y / p * p;
	if ((y - sy) % 2 == 1) {
		sy -= p;
		sn -= 1;
	}
	if ((y - sy) / 2 <= sn) {
		return true;
	}
	return false;
}
bool judge(int x, int y) {
	if (x > y) {
		swap(x, y);
	}
	if (x % 2 == 0 && x == y - 1) {
		return true;
	}
	if (x == 1 || x == 3) {
		return y % 2 == 0;
	}
	if (x == 2 || x == 4) {
		return true;
	}

	if (x % 2 == 0) {
		int p = x - 1;
		int q = x + 1;
		if (y >= p * q) {
			return true;
		} else {
			return check(y, p, q) || check(y - 1, p, q);
		}
	} else if (x % 2 == 1) {
		if (y % 2 == 1) {
			return false;
		} else {
			y /= 2;
			x /= 2;
			return y / x >= y % x;
		}
	} else {
		assert(0);
	}
}
int calc(int x) {
	int cnt = 0;
	for (int i = 5; i * i <= x; i++) {
		if (x % i == 0) {
			cnt++;
		}
	}
	if (cnt <= 200) {
		return 0;
	}
	cnt = 0;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			if (!judge(i, x / i)) {
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
//	printf("1320 %d\n", calc(1320));
//	return 0;
	int start = 21621600;
	int gqy = 0;
	while (true) {
		start += 2;
		int tmp = calc(start);
		if (tmp > gqy) {
			printf("%d %d\n", start, tmp);
			gqy = tmp;
		}
		if (tmp == 200) {
			printf("%d %d\n", start, tmp);
			return 0;
		}
	}
	return 0;
}
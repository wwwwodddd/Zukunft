#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int pos;
int same;
int v[50];
int n = 1000000;
int main() {
	pos = 0;
	for (int i = 0; i < n; i++) {
		int d1 = rand() % 4 + 1;
		int d2 = rand() % 4 + 1;
		if (d1 == d2) {
			same++;
		} else {
			same = 0;
		}
		pos += d1 + d2;
		pos %= 40;
		if (pos == 2 || pos == 17 || pos == 33) {
			int u = rand() % 16;
			if (u == 0) {
				pos = 0;
			} else if (u == 1) {
				pos = 10;
			}
		}
		if (pos == 7 || pos == 22 || pos == 36) {
			int u = rand() % 16;
			int w[] = {0, 10, 11, 24, 39, 5};
			if (u < 6) {
				pos = w[u];
			} else if (u == 6 || u == 7) {
				if (pos == 7) {
					pos = 12;
				} else if (pos == 22) {
					pos = 25;
				} else if (pos == 36) {
					pos = 5;
				}
			} else if (u == 8) {
				if (pos == 7) {
					pos = 12;
				} else if (pos == 22) {
					pos = 28;
				} else if (pos == 36) {
					pos = 12;
				}
			} else if (u == 9) {
				pos -= 3;
			}
		}
		if (pos == 30 || same == 3) {
			pos = 10;
		}
		v[pos]++;
		if (same == 3) {
			same = 0;
		}
	}
	for (int i = 0; i < 40; i++) {
		if (v[i] * 33 > n) {
			printf("%d %d\n", i, v[i]);
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int l, r, d[10];
int main() {
	scanf("%d%d", &l, &r);
	for (int i = l; i <= r; i++) {
		int y = i;
		while (y > 0) {
			d[y % 10]++;
			y /= 10;
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d%c", d[i], i == 9 ? '\n' : ' ');
	}
	return 0;
}

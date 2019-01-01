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
	printf("%d\n", d[2]);
	return 0;
}

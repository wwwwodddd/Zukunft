#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int c[6];
int t, n, m, x;
int a[110];
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			memset(c, 0, sizeof c);
			scanf("%d", &m);
			for (int i = 0; i < m; i++) {
				scanf("%d", &x);
				c[x - 1]++;
			}
			sort(c, c + 6);
			a[j] = m + c[2] + c[1] + 2 * c[0];
		}
		int big = 0;
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (a[j] > a[big]) {
				big = j;
				count = 1;
			} else if (a[j] == a[big]) {
				count++;
			}
		}
		if (count == 1) {
			if (big == 0) {
				printf("chef\n");
			} else {
				printf("%d\n", big + 1);
			}
		} else {
			printf("tie\n");
		}
	}
	return 0;
}

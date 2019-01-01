#include <bits/stdc++.h>
using namespace std;
int m, n, q[100020], b, f;
bool chuxian(int x) {
	for (int i = b; i < f; i++) {
		if (q[i] == x) {
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (!chuxian(x)) {
			q[f++] = x;
			if (f - b > m) {
				b++;
			}
		}
	}
	printf("%d\n", f);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, k, x, y;
char c;
int s[4020][4020];
int S(int x, int y) {
	return s[x][y] - s[x][y - k] - s[x - k][y] + s[x - k][y - k];
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d%d %c", &x, &y, &c);
		x %= 2 * k;
		y %= 2 * k;
		if (c == 'W') {
			x += k;
			x %= 2 * k;
		}
		x++;
		y++;
		s[x][y]++;
		s[x][y + 2 * k]++;
		s[x + 2 * k][y]++;
		s[x + 2 * k][y + 2 * k]++;
	}
	for (int i = 0; i < 4 * k; i++) {
		for (int j = 0; j < 4 * k; j++) {
			s[i + 1][j + 1] += s[i + 1][j] + s[i][j + 1] - s[i][j];
		}
	}
	int z = 0;
	for (int i = 2 * k; i <= 4 * k; i++) {
		for (int j = 2 * k; j <= 4 * k; j++) {
			z = max(z, S(i, j) + S(i - k, j - k));
		}
	}
	printf("%d\n", z);
	return 0;
}
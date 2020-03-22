#include <bits/stdc++.h>
using namespace std;
int a[60][60];
char s[1020][1020], c[9][9] = {
"@@+---+",
"@/   /|",
"+---+ |",
"|   | +",
"|   |/@",
"+---+@@"};
int n, m, xm, ym;
void gao(int x, int y) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			if (c[i][j] != '@') {
				s[x + 5 - i][y + j] = c[i][j];
				xm = max(xm, x + 5 - i);
				ym = max(ym, y + j);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	memset(s, '.', sizeof s);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			for (int k = 0; k < a[i][j]; k++) {
				gao((n - i - 1) * 2 + k * 3, (n - i - 1) * 2 + j * 4);
			}
		}
	}
	for (int i = xm; i >= 0; i--) {
		s[i][ym+1] = 0;
		printf("%s\n", s[i]);
	}
}
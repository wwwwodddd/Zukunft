#include <bits/stdc++.h>
using namespace std;
char s[120][120];
int h, w;
bool a[120], b[120];
int main() {
	scanf("%d%d", &h, &w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf(" %c", &s[i][j]);
			if (s[i][j] == '#') {
				a[i] = true;
				b[j] = true;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		if (a[i]) {
			for (int j = 0; j < w; j++) {
				if (b[j]) {
					printf("%c", s[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
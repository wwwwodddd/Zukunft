#include <bits/stdc++.h>
using namespace std;
int t, n, a;
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d", &n, &a);
		if (a == 1) {
			printf("%d ", n);
			for (int i = 0; i < n; i++) {
				printf("a");
			}
			printf("\n");
		}
		if (a == 2) {
			if (n > 8) {
				printf("%d ", 4);
				char s[] = "abaabb";
				for (int i = 0; i < n; i++) {
					printf("%c", s[i % 6]);
				}
				printf("\n");
			} else if (n > 4) {
				printf("%d ", 3);
				char s[] = "aaababbb";
				for (int i = 0; i < n; i++) {
					printf("%c", s[i]);
				}
				printf("\n");
			} else if (n > 2) {
				printf("%d ", 2);
				char s[] = "aabb";
				for (int i = 0; i < n; i++) {
					printf("%c", s[i]);
				}
				printf("\n");
			} else {
				printf("%d ", 1);
				char s[] = "ab";
				for (int i = 0; i < n; i++) {
					printf("%c", s[i]);
				}
				printf("\n");
			}
		}
		if (a > 2) {
			printf("%d ", 1);
			for (int i = 0; i < n; i++) {
				printf("%c", 'a' + i % 3);
			}
			printf("\n");
		}
	}
	return 0;
}

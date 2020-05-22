#include <bits/stdc++.h>
using namespace std;
char s[100020];
int main() {
	scanf("%s", s);
	for (int i = 0; s[i]; i++) {
		if (s[i] == s[i + 1]) {
			printf("%d %d\n", i + 1, i + 2);
			return 0;
		}
		if (s[i] == s[i + 2]) {
			printf("%d %d\n", i + 1, i + 3);
			return 0;
		}
	}
	printf("-1 -1\n");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
char s[100020];
int t;
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%s", s);
		int z[2] = {};
		int last = 0;
		char ch = 0;
		for (int i = 0; s[i]; i++) {
			if (s[i] == 'A' || s[i] == 'B') {
				if (s[i] == ch) {
					z[s[i] - 'A'] += i - last;
				} else {
					ch = s[i];
					z[s[i] - 'A']++;
				}
				last = i;
			}
		}
		printf("%d %d\n", z[0], z[1]);
	}
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;
int t;
char s[100020];
int c[2];
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%s", s);
		c[0] = c[1] = 0;
		for (int i = 0; s[i]; i++) {
			c[s[i] - '0']++;
		}
		if (c[0] == 1 || c[1] == 1) {
			puts("Yes");
		} else {
			puts("No");
		}
	}
}

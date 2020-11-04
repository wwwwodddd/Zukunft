#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t;
char s[100020];
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%s", s);
		int n = strlen(s);
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (s[i] == '.') {
				if (s[n - i - 1] == '.') {
					s[i] = s[n - i - 1] = 'a';
				} else {
					s[i] = s[n - i - 1];
				}
			} else if (s[n - i - 1] != '.' && s[i] != s[n - i - 1]) {
				flag = false;
			}
		}
		if (flag) {
			printf("%s\n", s);
		} else {
			puts("-1");
		}
	}
}

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int cnt;
void F(int x, int y) {
//	printf("%d %d\n", x, y);
	char s[] = "a(Yb(Z)a)z(Az)y(By)";
	int l = strlen(s);
	for (int i = 0; i < l; i++) {
		if (s[i] == 'a') {
			s[i] = 'a' + x;
		} else if(s[i] == 'A') {
			s[i] = 'A' + x;
		} else if(s[i] == 'b') {
			s[i] = 'a' + y;
		} else if(s[i] == 'B') {
			s[i] = 'A' + y;
		}
	}
	if (x < 24 && y < 24) {
		printf("%s\n", s);
	}
}
void S(int x, int y) {
	if (y == 1) {
		return;
	}
	S(x, y / 2), S(x + y / 2, y / 2);
	for (int i = 0; i < y / 2; i++) {
		F(x + i, x + y - i - 1);
	}
	for (int i = y / 2; i > 1; i /= 2) {
		for (int j = x; j < x + y; j += i) {
			for (int k = 0; k < i / 2; k++) {
				F(j + k, j + k + i / 2);
			}
		}
	}
}
int main() {
	S(0, 32);
	return 0;
}
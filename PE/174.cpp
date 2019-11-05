#include <iostream>
#include <cstdio>
using namespace std;
int l[1000020];
int main() {
	for (int i = 1; i <= 1000000; i++) {
		for (int j = i - 2; j >= 1 && i * i - j * j <= 1000000; j -= 2) {
			l[i * i - j * j] += 1;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 1000000; i++) {
		if (1 <= l[i] && l[i] <= 10) {
//		if (l[i] == 15) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
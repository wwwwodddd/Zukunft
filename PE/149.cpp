#include <stdio.h>
#include <iostream>
using namespace std;
int s[4000020];
int a[2020][2020];
int n = 2000;
int z;
int main() {
	for (int i = 1; i <= 55; i++) {
		s[i] = (100003 - 200003 * i + 300007LL * i * i * i) % 1000000 - 500000;
	}
	for (int i = 56; i <= 4000000; i++) {
		s[i] = (s[i - 24] + s[i - 55] + 1000000) % 1000000 - 500000;
//		s[i] = (s[i - 24] + s[i - 55] + 1000000) % 1000000 - 500000;
	}
	printf("%d\n", s[100]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = s[i * n + j + 1];
		}
	}

	for (int i = 0; i < n; i++) {
		int s1 = 0;
		int s2 = 0;
		for (int j = 0; j < n; j++) {
			s1 = max(0, s1 + a[i][j]);
			s2 = max(0, s2 + a[j][i]);
			z = max(z, max(s1, s2));
		}
	}

	for (int i = 0; i < n; i++) {
		int s1 = 0;
		int s2 = 0;
		for (int j = 0; i + j < n; j++) {
			s1 = max(0, s1 + a[j][i + j]);
			s2 = max(0, s2 + a[i + j][j]);
			z = max(z, max(s1, s2));
		}
	}

	for (int i = 0; i < n; i++) {
		reverse(a[i], a[i] + n);
	}

	for (int i = 0; i < n; i++) {
		int s1 = 0;
		int s2 = 0;
		for (int j = 0; i + j < n; j++) {
			s1 = max(0, s1 + a[j][i + j]);
			s2 = max(0, s2 + a[i + j][j]);
			z = max(z, max(s1, s2));
		}
	}

	printf("%d\n", z);	
	return 0;
}
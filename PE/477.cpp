#include <stdio.h>
#include <iostream>
using namespace std;
int p = 1000000007;
int F(int x) {
	return ((long long)x * x + 45) % p;
}
int l, r;
int main() {
	l = 0;
	r = 0;
	int s = 0, c = 0;
	do {
		l = F(l);
		r = F(F(r));
		s++;
	} while (l != r);
	do {
		r = F(r);
		c++;
	} while (l != r);
	printf("%d %d\n", s, c);
	return 0;
}
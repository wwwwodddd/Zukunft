#include <bits/stdc++.h>
using namespace std;
unsigned long long s;
double x;
int main() {
	while (cin >> x) {
		s += (unsigned long long)(x * 1000000 + 0.5);
	}
	s = s / 10 + (s % 10 >= 5);
	printf("%llu.%05llu", s / 100000, s % 100000);
	return 0;
}
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

/*


n^2 = 2 x^2 + 2 y^2
n = 2m

2 m^2 = x^2 + y^2
x = a + b
y = a - b
m^2 = a^2 + b^2

*/

//long long n = 100000000000LL;
long long n = 359125 * 2;
long long gcd(long long x, long long y) {
	return y ? gcd(y, x % y) : x;
}
vector<long long>num;
int main() {
	for (long long i = 1; i < n; i++) {

	}
	for (long long i = 1; i * i <= n; i++) {
		for (long long j = 1; j < i; j++) {
			if (gcd(i, j) > 1) {
				continue;
			}
			if (i % 2 == 1 && j % 2 == 1) {
				continue;
			}
			long long a = i * i - j * j;
			long long b = 2 * i * j;
			long long c = i * i + j * j;
			if (c <= n / 2 && n / 2 % c == 0) {
				printf("%lld %lld %lld\n", c, a, b);
				num.push_back(c);
			}
		}
	}
	printf("%lu\n", num.size());
	return 0;
}
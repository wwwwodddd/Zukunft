#include <bits/stdc++.h>
using namespace std;
long long F(long long n) {
	return n - (n + 2) / 4;
}
int main() {
	long long l, r;
	cin >> l >> r;
	l += 4e9;
	r += 4e9;
	printf("%lld\n", F(r) - F(l - 1));
	return 0;
}
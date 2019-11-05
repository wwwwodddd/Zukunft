#include <bits/stdc++.h>
using namespace std;
long long n = 1e2;
int main() {
	
	for (int i = 2; i * i <= n; i++) {
		if (isPrime(i)) {
			ans -= i - 1;
		}
	}
	return 0;
}
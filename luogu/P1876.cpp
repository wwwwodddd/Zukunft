#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
	cin >> n;
	for (long long i = 1; i * i <= n; i++) {
		cout << i * i << ' ';
	}
	return 0;
}

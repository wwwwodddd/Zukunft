#include <bits/stdc++.h>
using namespace std;
long long z;
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		z += n / i;
	}
	cout << z << endl;
}
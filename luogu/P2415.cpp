#include <bits/stdc++.h>
using namespace std;
long long s;
int x, n;
int main() {
	while (cin >> x) {
		s += x;
		n++;
	}
	cout << (s << (n - 1)) << endl;
	return 0;
}

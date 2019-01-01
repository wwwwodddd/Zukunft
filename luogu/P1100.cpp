#include <bits/stdc++.h>
using namespace std;
long long x;
int main() {
	cin >> x;
	cout << ((x >> 16) + ((x & 65535) << 16)) << endl;
	return 0;
}

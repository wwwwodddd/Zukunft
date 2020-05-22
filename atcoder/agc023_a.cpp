#include <bits/stdc++.h>
using namespace std;
int n, x;
long long z, s;
map<long long, int> g;
int main() {
	cin >> n;
	g[s] = 1;
	for (int i = 0; i < n; i++) {
		cin >> x;
		z += g[s += x]++;
	}
	cout << z << endl;
	return 0;
}
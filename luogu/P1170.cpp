#include <bits/stdc++.h>
using namespace std;
int n, ax, ay, bx, by;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ax >> ay >> bx >> by;
		cout << (__gcd(abs(ax - bx), abs(ay - by)) == 1 ? "no" : "yes") << endl;
	}
}
#include <bits/stdc++.h>
using namespace std;
int R, B, C, D, E;
int main() {
	cin >> R >> B >> C >> D >> E;
	cout << R * C + B * D + min(R, B) * max(0, 2 * E - C - D) << endl;
	return 0;
}

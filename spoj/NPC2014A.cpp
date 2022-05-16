#include <iostream>
using namespace std;
int t, n, x;
int F(int x) {
	for (int i = 0; i < 32; i++) {
		if (x >> i & 1) {
			return i;
		}
	}
	return 0;
}

int main() {
	for (scanf("%d", &t); t--;) {
		scanf("%d", &n);
		int z = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			z ^= F(x);
		}
		puts(z ? "Puguh is the bestest player in teh wurld" : "Joke is the bestest player in teh wurld");
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
long long r = 1;
long long cao = 729809891;
long long sum = 0;
int main() {
//	for (int i = 0; i < 729909891; i++) {
	for (int i = 0; i < cao - 1; i++) {
		r = r * 10;
		sum += r / cao;
		r %= cao;
	}
	printf("%lld\n", sum);
	printf("\n");
	return 0;
}
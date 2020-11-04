#include <iostream>
#include <cstdio>
using namespace std;
int n, p;
int main() {
	scanf("%d%d", &n, &p);
	for (int i = 1; i < p; i++) {
		printf("%d ", n / p * i);
	}
	printf("\n");
	for (int i = 1; i < p; i++) {
		printf("%d ", n / p * i);
	}
	printf("\n");
}
#include <bits/stdc++.h>
using namespace std;
char s[10020];
int p = 19260817;
int read() {
	// 读入一个数字mod p的结果 
	scanf("%s", s);
	int n = strlen(s);
	int u = 0;
	for (int i = 0; i < n; i++) {
		u = u * 10 + s[i] - '0';
		u %= p;
	}
	return u;
}
long long pw(long long x, long long y, long long p) {
	long long re = 1;
	for (; y; y >>= 1) {
		if (y & 1) {
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
int main() {
	int A = read();
	int B = read();
	if (B == 0) {
		printf("Angry!");
	} else {
		cout << (A * pw(B, p - 2, p) % p) << endl;
	}
}

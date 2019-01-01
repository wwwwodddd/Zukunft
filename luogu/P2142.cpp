#include <bits/stdc++.h>
using namespace std;
string A, B;
int a[10020];
int b[10020];
bool cmp(const string &A, const string &B) {
	if (A.size() != B.size()) {
		return A.size() < B.size();
	}
	return A < B;
}
int main() {
	cin >> A >> B;
	if (cmp(A, B)) {
		swap(A, B);
		printf("-");
	}
	for (int i = 0; i < A.size(); i++) {
		a[i] = A[A.size() - i - 1] - '0';
	}
	for (int i = 0; i < B.size(); i++) {
		b[i] = B[B.size() - i - 1] - '0';
	}
	for (int i = 0; i < B.size(); i++) {
		a[i] -= b[i];
	}
	for (int i = 0; i < A.size(); i++) {
		while (a[i] < 0) {
			a[i] += 10;
			a[i + 1]--;
		}
	}
	int l = A.size();
	while (l > 0 && a[l] == 0) {
		l--;
	}
	for (int i = l; i >= 0; i--) {
		printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, A, B, C;
int a[10000020];
int main() {
	scanf("%d%d%d%d%d",&n,&A,&B,&C,a+1);
	for (int i=2;i<=n;i++)
		a[i] = ((long long)a[i-1] * A + B) % 100000001;
	for (int i=1;i<=n;i++)
		a[i] = a[i] % C + 1;
	a[0] = a[n];
	double ans = 0;
	for (int i = 0; i < n; i++) {
		ans += 1.0 / max(a[i], a[i + 1]);
	}
	printf("%.3f\n", ans);
	return 0;
}
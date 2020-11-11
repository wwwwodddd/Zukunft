#include <bits/stdc++.h>
using namespace std;
int n, w, h, x;
int main() {
	scanf("%d%d%d", &n, &w, &h);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		puts(w * w + h * h < x * x ? "NE" : "DA");
	}
	return 0;
}
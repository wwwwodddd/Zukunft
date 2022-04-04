#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main()
{
	cin >> a >> b >> c >> d;
	cout << (c * 60 + d < a * 60 + b ? "Aoki" : "Takahashi") << endl;
	return 0;
}

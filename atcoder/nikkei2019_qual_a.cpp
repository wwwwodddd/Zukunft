#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main()
{
	cin >> n >> a >> b;
	cout << min(a, b) << " " << max(a + b - n, 0) << endl;
	return 0;
}

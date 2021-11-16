#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main()
{
	cin >> a >> b >> c >> d;
	cout << max(min(b, d) - max(a, c), 0) << endl;
	return 0;
}

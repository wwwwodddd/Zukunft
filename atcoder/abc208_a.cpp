#include <bits/stdc++.h>
using namespace std;
int a, b;
int main()
{
	cin >> a >> b;
	cout << (a <= b && b <= 6 * a ? "Yes" : "No") << endl;
	return 0;
}

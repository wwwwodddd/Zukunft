#include <bits/stdc++.h>
using namespace std;
int a, b;
int main()
{
	cin >> a >> b;
	cout << max(b - a + 1, 0) << endl;
	return 0;
}

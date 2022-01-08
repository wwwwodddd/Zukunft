#include <bits/stdc++.h>
using namespace std;
int w, a, b;
int main()
{
	cin >> w >> a >> b;
	cout << max(abs(a - b) - w, 0) << endl;
	return 0;
}

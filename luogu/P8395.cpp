#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	cout << (n - n % 4 * 5 + 20) / 20 << endl;
	return 0;
}

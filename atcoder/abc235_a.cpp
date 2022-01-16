#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	cout << (n / 100 + n / 10 % 10 + n % 10) * 111 << endl;
	return 0;
}

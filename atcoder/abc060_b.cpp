#include <bits/stdc++.h>
using namespace std;
int A, B, C;
int main()
{
	cin >> A >> B >> C;
	cout << (C % __gcd(A, B) == 0 ? "YES" : "NO") << endl;
	return 0;
}

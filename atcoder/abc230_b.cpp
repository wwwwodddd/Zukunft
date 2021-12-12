#include <bits/stdc++.h>
using namespace std;
int main()
{
	string t, s = "oxxoxxoxxoxx";
	cin >> t;
	cout << (~s.find(t) ? "Yes" : "No") << endl;
	return 0;
}

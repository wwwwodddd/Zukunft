#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	n = n * 27 / 25;
	cout << (n < 206 ? "Yay!" : n > 206 ? ":(" : "so-so") << endl;
}

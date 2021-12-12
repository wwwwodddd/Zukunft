#include <bits/stdc++.h>
using namespace std;
string a, b;
int main()
{
	cin >> a >> b;
	cout << (a == "#." && b== ".#" || a == ".#" && b== "#." ? "No" : "Yes") << endl; 
	return 0;
}

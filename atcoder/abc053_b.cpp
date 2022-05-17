#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	cout << s.rfind("Z") - s.find("A") + 1 << endl;
}

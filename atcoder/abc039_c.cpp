#include <bits/stdc++.h>
using namespace std;
string s = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW", t;
string z[] = {"Do", "Do", "Re", "Re", "Mi", "Fa", "Fa", "So", "So", "La", "La", "Si"};
int main()
{
	cin >> t;
	cout << z[s.find(t)] << endl;
	return 0;
}

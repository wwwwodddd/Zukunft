#include <bits/stdc++.h>
using namespace std;
int n;
long long z;
string s;
map<string, int> g;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		sort(s.begin(), s.end());
		z += g[s]++;
	}
	cout << z << endl;
	return 0; 
}

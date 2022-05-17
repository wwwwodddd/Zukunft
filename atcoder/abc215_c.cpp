#include <bits/stdc++.h>
using namespace std;
string s;
int k;
int main()
{
	cin >> s >> k;
	sort(s.begin(), s.end());
	for (int i = 1; i < k; i++)
	{
		cout << s << endl;
		next_permutation(s.begin(), s.end());
	}
	cout << s << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	int i = 0, j = s.size() - 1;
	while (i < j && s[j] == 'a')
	{
		j--;
		if (s[i] == 'a')
		{
			i++;
		}
	}
	while (i < j && s[i] == s[j])
	{
		i++;
		j--;
	}
	cout << (i < j ? "No" : "Yes") << endl;
	return 0;
}
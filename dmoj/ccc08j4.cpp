#include <bits/stdc++.h>
using namespace std;
int t;
vector<string> z;
void gao()
{
	string o;
	cin >> o;
	if (isdigit(o[0]))
	{
		z.push_back(o);
	}
	else
	{
		gao();
		gao();
		z.push_back(o);
	}
}
int main()
{
	while (true)
	{
		z.clear();
		gao();
		if (z.size() == 1 && z[0] == "0")
		{
			break;
		}
		for (string i : z)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}
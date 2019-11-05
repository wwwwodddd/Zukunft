#include <bits/stdc++.h>
using namespace std;
int gao(int L, int n)
{
	const int d = 1000;
	double pw = 1;
	for (int i = 0;; i++)
	{
		if (int(pw) == L)
		{
			if (n == 1)
			{
				return i;
			}
			n--;
		}
		pw = pw * 2;
		if (pw >= d)
		{
			pw /= 10;
		}
	}
	return -1;
}
int main()
{
	cout << gao(123, 45) << endl;
	cout << gao(123, 678910) << endl;
	return 0;
}

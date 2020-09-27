#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x)
{
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	vector<int> a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(5);
	a.push_back(7);
	cin >> n;
	vector<int> b;
	for (int i = 1; i < n; i++)
	{
		for (int i: a)
		{
			for (int j = 1; j < 10; j += 2)
			{
				if (isPrime(10 * i + j))
				{
					b.push_back(10 * i + j);
				}
			}
		}
		a.swap(b);
		b.clear();
	}
	for (int i: a)
	{
		printf("%d\n", i);
	}
	return 0;
}
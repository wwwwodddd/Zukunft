#include <bits/stdc++.h>
using namespace std;
int get()
{
	char c;
	while (!isdigit(c = getchar()))
	{
	}
	int x = c - '0';
	while (isdigit(c = getchar()))
	{
		x = x * 10 + c - '0';
	}
	return x;
}
int c[1000020];
long long q1[1000020];
long long q2[1000020];
int b1, f1, b2, f2;
long long pop()
{
	if (b2 == f2 || (b1 < f1 && q1[b1] < q2[b2]))
	{
		return q1[b1++];
	}
	else
	{
		return q2[b2++];
	}
}
int main()
{
	int t = get();
	for (int tt = 0; tt < t; tt++)
	{
		b1 = f1 = b2 = f2 = 0;
		int n = get();
		for (int i = 0; i < n; i++)
		{
			c[get()]++;
		}
		for (int i = 1; i <= 1000000; i++)
		{
			for (; c[i]; c[i]--)
			{
				q1[f1++] = i;
			}
		}
		long long z = 0;
		for (int i = 1; i < n; i++)
		{
			long long x = pop();
			long long y = pop();
			z += x + y;
			q2[f2++] = x + y;
		}
		cout << z << endl;
	}
	return 0;
}
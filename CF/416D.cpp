#include <bits/stdc++.h>
using namespace std;
int n, flag;
long long z, x, f, p, v, k;
// f 当前等差数列第一项在哪里 
// p 不是-1的那一项下标是什么
// v 不是-1的那一项值是多少
// k 最后一个等差数列的公差是多少
// flag
// 0这是第一个数字 
// 1最后一个等差数列全是 -1
// 2最后一个等差数列只有1个不是-1
// 3最后一个等差数列有2个不是-1
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (flag == 0)
		{
			if (x == -1)
			{
				z++;
				flag = 1;
				f = i;
			}
			else
			{
				z++;
				flag = 2;
				f = i;
				p = i;
				v = x;
			}
		}
		else if (flag == 1)
		{
			if (x == -1)
			{
				
			}
			else
			{
				flag = 2;
				p = i;
				v = x;
			}
		}
		else if (flag == 2)
		{
			if (x == -1)
			{
				
			}
			else
			{
				if ((x - v) % (i - p) == 0 && v - (x - v) / (i - p) * (p - f) > 0)
				{
					flag = 3;
					k = (x - v) / (i - p);
				}
				else
				{
					z++;
					flag = 2;
					f = i;
					p = i;
					v = x;
				}
			}
		}
		else if (flag == 3)
		{
			if (x == -1)
			{
				if (v + (i - p) * k > 0)
				{
					
				}
				else
				{
					z++;
					flag = 1;
					f = i;
				}
			}
			else
			{
				if (v + (i - p) * k == x)
				{
					
				}
				else
				{
					z++;
					flag = 2;
					f = i;
					p = i;
					v = x;
				}
			}
		}
	}
	cout << z << endl;
	return 0;
}